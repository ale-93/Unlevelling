// Fill out your copyright notice in the Description page of Project Settings.

#include "Unlevelling.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAIController.h"
#include "BTTask_StopSearch.h"
#include "Engine.h"

EBTNodeResult::Type UBTTask_StopSearch::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	AEnemyAIController * EnemyAIController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());
	ACharacter *Player = Cast<ACharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(EnemyAIController->TargetKey));
	AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(EnemyAIController->GetCharacter());
	UPawnSensingComponent* PawnSensingComponent = Cast<UPawnSensingComponent>(EnemyCharacter->GetComponentByClass(UPawnSensingComponent::StaticClass()));
	
	if (Player && EnemyAIController && EnemyCharacter && PawnSensingComponent) {
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Here!");
		if (EnemyAIController) {
			float distance;
			if (Player && PawnSensingComponent) {
				distance = EnemyCharacter->GetDistanceTo(Player);
				GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Distance Found");
				FHitResult Hit;
				FVector EyeLocation;
				FRotator EyeRotation;
				ECollisionChannel Channel = ECollisionChannel::ECC_Visibility;
				EnemyCharacter->GetActorEyesViewPoint(EyeLocation, EyeRotation);
				GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, Player->GetActorLocation(), Channel);
				if (distance > PawnSensingComponent->SightRadius)
				{
					if(Hit.GetActor())
						UE_LOG(LogTemp, Warning, TEXT("Attacking %s"), *(Hit.GetActor()->GetName()));

					GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Stop Movement!");
					OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyAIController->TargetKey, nullptr);
					EnemyAIController->StopMovement();
					return EBTNodeResult::Succeeded;
				}
			}
		}
	}
	return::EBTNodeResult::Failed;
}






