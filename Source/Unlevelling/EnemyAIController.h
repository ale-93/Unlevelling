// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class UNLEVELLING_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(transient)
	class UBlackboardComponent* BlackboardComponent;

	UPROPERTY(transient)
	class UBehaviorTreeComponent* EnemyBehaviorComponent;

public:
	
	AEnemyAIController();

	virtual void Possess(APawn *InPawn) override;

	uint8 EnemyKeyID;
	uint8 TargetKey;

	// Sets the new sensed target value inside our Blackboard values
	void SetSensedTarget(APawn* NewTarget);

	
};
