// Fill out your copyright notice in the Description page of Project Settings.

#include "Unlevelling.h"
#include "PlayerCharacterComponent.h"
#include "EnemyCharacter.h"

// Sets default values for this component's properties
UPlayerCharacterComponent::UPlayerCharacterComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	bAttackStarted = false;
	bAnimAttackStarted = false;

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
	/*Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner());
	const USkeletalMeshSocket* Hand_R_Socket = ownerCharacter->GetMesh()->GetSocketByName(FName("Hand_R"));
	if (Hand_R_Socket) {
		//UE_LOG(LogTemp, Warning, TEXT("Found Hand_R_Socket"));
		TArray<FHitResult> HitResults;
		FCollisionQueryParams CollisionQueryParams;
		FCollisionObjectQueryParams CollisionObjectsQueryParams;
		FVector SocketLocation;
		FQuat SocketRotation;
		ownerCharacter->GetMesh()->GetSocketWorldLocationAndRotation(FName("Hand_R"), SocketLocation, SocketRotation);*/
		/*DrawDebugLine(GetWorld(), Hand_R_Socket->GetSocketLocation(ownerCharacter->GetMesh()),
			Hand_R_Socket->GetSocketLocation(ownerCharacter->GetMesh())+ownerCharacter->GetMesh()->GetUpVector()*100,
			FColor(255,0,0), false,-1.f,(uint8)'\000',5.f);*/
		/*DrawDebugLine(GetWorld(), SocketLocation,
			SocketLocation + SocketRotation.GetUpVector()*100,
			FColor(255, 0, 0), false, -1.f, (uint8)'\000', 5.f);
		
		CollisionQueryParams.AddIgnoredActor(GetOwner());

		bool HitSuccess = GetWorld()->LineTraceMultiByObjectType(HitResults, SocketLocation, SocketRotation.GetUpVector() * 100, CollisionObjectsQueryParams, CollisionQueryParams);
		if (HitSuccess) {
			for (auto hit : HitResults) {
				USkeletalMeshComponent* ActorSkeletalMesh = Cast<USkeletalMeshComponent>(hit.GetComponent());
				if (ActorSkeletalMesh) {
					AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(hit.GetActor());
					UE_LOG(LogTemp, Warning, TEXT("Hit %s"), *hit.GetComponent()->GetName());
					if (EnemyCharacter) {
						UE_LOG(LogTemp, Warning, TEXT("Hit %s"), *hit.GetActor()->GetName());

					}
				}
			}

		}
	}*/
	
}

void UPlayerCharacterComponent::SetupPlayerInputComponent() {
	ACharacter* ownerCharacter = Cast<ACharacter>(GetOwner());
	UInputComponent * PlayerInputComponent = ownerCharacter->InputComponent;
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &UPlayerCharacterComponent::Attack);
	//PlayerInputComponent->BindAction("Attack", IE_Released, this, &UPlayerCharacterComponent::StopAttackAnimation);

}

void UPlayerCharacterComponent::Attack() {
	if (!bAttackStarted) {
		bAttackStarted = true;
		bAnimAttackStarted = true;
		UE_LOG(LogTemp, Warning, TEXT("Attacked!"));
		GetWorld()->GetTimerManager().SetTimer(AnimTimerHandle, this, &UPlayerCharacterComponent::StopAnimAttackAnimation, 0.1f);
		GetWorld()->GetTimerManager().SetTimer(AttackTimerHandle, this, &UPlayerCharacterComponent::StopAttackAnimation, 1.0f);
	}
}

void UPlayerCharacterComponent::StopAttackAnimation() {
	bAttackStarted = false;
	ResetTarget.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("Attack Ended!"));
}

void UPlayerCharacterComponent::StopAnimAttackAnimation() {
	bAnimAttackStarted = false;
	UE_LOG(LogTemp, Warning, TEXT("Attack Ended!"));
}
