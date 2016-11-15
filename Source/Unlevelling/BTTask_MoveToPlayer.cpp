// Fill out your copyright notice in the Description page of Project Settings.

#include "Unlevelling.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAIController.h"
#include "BTTask_MoveToPlayer.h"

EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	AEnemyAIController * EnemyAIController = Cast<AEnemyAIController>(OwnerComp.GetAIOwner());

	// Get the enemy (= the player) from the blackboard
	ACharacter *Player = Cast<ACharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(EnemyAIController->TargetKey));
	UCharacterMovementComponent* MovementComponent = Player->GetCharacterMovement();

	if (Player) {
		EnemyAIController->MoveToActor(Player, 5.f, true, true, true, 0, true);
		return EBTNodeResult::Succeeded;
	}
	return::EBTNodeResult::Failed;
}



