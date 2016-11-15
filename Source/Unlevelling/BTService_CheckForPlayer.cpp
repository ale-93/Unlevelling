// Fill out your copyright notice in the Description page of Project Settings.

#include "Unlevelling.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAIController.h"
#include "BTService_CheckForPlayer.h"
#include "Engine.h"


UBTService_CheckForPlayer::UBTService_CheckForPlayer() {
	bCreateNodeInstance = true;
}

void UBTService_CheckForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	AEnemyAIController * EnemyAIController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());

	if (EnemyAIController) {
		// Get the player character
		ACharacter *Player = Cast<ACharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (Player) {
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(EnemyAIController->EnemyKeyID, Player);
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Enemy Found Player!");
		}
	}

}



