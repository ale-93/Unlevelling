// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Perception/PawnSensingComponent.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class UNLEVELLING_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Sensing function that will be executed when we sense a Pawn
	UFUNCTION()
	void OnPawnSensed(APawn* PawnInstigator);

	// A Pawn Sensing Component, responsible for sensing other Pawns
	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSensingComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= Behavior)
	class UBehaviorTree* EnemyBehavior;

	void SearchForTarget();

	void Move();

	void Attack();

protected:
	bool bRangedAttack;

	float TargetDistance;
};
