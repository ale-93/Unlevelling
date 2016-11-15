// Fill out your copyright notice in the Description page of Project Settings.

#include "Unlevelling.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyCharacter.h"
#include "EnemyAIController.h"

AEnemyAIController::AEnemyAIController() {
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	EnemyBehaviorComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("EnemyBehaviorTreeComponent"));
}

void AEnemyAIController::Possess(APawn *InPawn) {
	Super::Possess(InPawn);

	AEnemyCharacter *EnChar = Cast<AEnemyCharacter>(InPawn);

	// Se non sono null pointer
	if (EnChar && EnChar->EnemyBehavior) {
		BlackboardComponent->InitializeBlackboard(*(EnChar->EnemyBehavior->BlackboardAsset));

		EnemyKeyID = BlackboardComponent->GetKeyID("Target");
		TargetKey = BlackboardComponent->GetKeyID("SensedPawn");

		EnemyBehaviorComponent->StartTree(*(EnChar->EnemyBehavior));
	}
}

void AEnemyAIController::SetSensedTarget(APawn * NewTarget) {
	//Set a new target to follow
	if (BlackboardComponent) BlackboardComponent->SetValue<UBlackboardKeyType_Object>(TargetKey, NewTarget);
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, "Enemy Sensed Player!");

}
