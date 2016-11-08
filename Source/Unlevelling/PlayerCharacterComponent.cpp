// Fill out your copyright notice in the Description page of Project Settings.

#include "Unlevelling.h"
#include "PlayerCharacterComponent.h"

// Sets default values for this component's properties
UPlayerCharacterComponent::UPlayerCharacterComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	bAttackStarted = false;

	// ...
}

// Called when the game starts
void UPlayerCharacterComponent::BeginPlay() {

	Super::BeginPlay();
	SetupPlayerInputComponent();


	// ...
	
}

// Called every frame
void UPlayerCharacterComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) {
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UPlayerCharacterComponent::SetupPlayerInputComponent() {
	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner());
	UInputComponent * PlayerInputComponent = ownerCharacter->InputComponent;
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &UPlayerCharacterComponent::Attack);
}

void UPlayerCharacterComponent::Attack() {
	bAttackStarted = true;
	UE_LOG(LogTemp, Warning, TEXT("Attacked!"));
}

