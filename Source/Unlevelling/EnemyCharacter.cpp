// Fill out your copyright notice in the Description page of Project Settings.

#include "Unlevelling.h"
#include "EnemyCharacter.h"
#include "EnemyAIController.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Initializing our Pawn Sensing comp
	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (PawnSensingComp)
	{
		//Registering the delegate which will fire when we hear something
		PawnSensingComp->OnSeePawn.AddDynamic(this, &AEnemyCharacter::OnPawnSensed);
	}
	
}

// Called every frame
void AEnemyCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AEnemyCharacter::OnPawnSensed(APawn * PawnInstigator) {
	AEnemyAIController* EnemyAIController = Cast<AEnemyAIController>(GetController());

	if (EnemyAIController && PawnInstigator != this)
	{
		// Updates our target based on what we've seen
		EnemyAIController->SetSensedTarget(PawnInstigator);
	}
}

void AEnemyCharacter::SearchForTarget() {
}

