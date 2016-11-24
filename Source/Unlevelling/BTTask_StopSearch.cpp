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
	
	if (Player) {
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, "Here!");
		if (EnemyAIController) {
			float distance;
			if (Player) {
				distance = EnemyAIController->GetOwner()->GetDistanceTo(Player);
				if (distance > 0.1f)
				{
					EnemyAIController->StopMovement();
					GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Search Stopped!");
					return EBTNodeResult::Succeeded;
				}
			}
		}
	}
	return::EBTNodeResult::Failed;
}






