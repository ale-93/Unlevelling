// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "PlayerCharacterComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNLEVELLING_API UPlayerCharacterComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	void SetupPlayerInputComponent();
	void Attack();
public:	
	// Sets default values for this component's properties
	UPlayerCharacterComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UPROPERTY(BlueprintReadWrite, Category = AnimationState)
	bool bAttackStarted;
	UPROPERTY(BlueprintReadWrite, Category = AnimationState)
	bool bAnimAttackStarted;

	FTimerHandle AttackTimerHandle;

	FTimerHandle AnimTimerHandle;

	void StopAttackAnimation();

	void StopAnimAttackAnimation();
	
};
