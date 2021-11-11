// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

// Sets default values
AMyPawn::AMyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = Capsule;
	RootComponent->SetupAttachment(Capsule);

	SphereDetectionInteraction = CreateDefaultSubobject<UCapsuleComponent>("SphereDetectionInteraction");
	SphereDetectionInteraction->SetupAttachment(RootComponent);
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SkeletalMesh->SetupAttachment(RootComponent);
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("FloatingPawnMovement");
	if(RootComponent != nullptr)
	{
		Camera->SetupAttachment(SpringArm);
		SpringArm->SetupAttachment(RootComponent);
	}

	//AddComponent(FloatingPawnMovement)
	SpringArm->SetRelativeLocationAndRotation(FVector(0,0,90), FRotator(-10,0,0));

	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritRoll = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	SpeedAnim = 0.f;
}

void AMyPawn::RemoveActorInteractable(AMyActorInteractable* _targetActor)
{
	if(ArrayOfActorsInteractable.Find(_targetActor) != INDEX_NONE)
	{
		//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Red, FString::Printf(TEXT("Remove %s to array "), *_targetActor->GetName()));
		ArrayOfActorsInteractable.Remove(_targetActor);
	}
}

void AMyPawn::RemoveActorInteractableFromInventory(AMyActorInteractable* _targetActor)
{
	if(InventoryOfActorsInteractable.Find(_targetActor) != INDEX_NONE)
	{
		//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Red, FString::Printf(TEXT("Remove %s to array "), *_targetActor->GetName()));
		InventoryOfActorsInteractable.Remove(_targetActor);
	}
}
void AMyPawn::Interact() 
{
	if(ArrayOfActorsInteractable.Num() > 0 && ArrayOfActorsInteractable[0] != nullptr )
	{
		//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Magenta, FString::Printf(TEXT("Pawn interact with %s"), *ArrayOfActorsInteractable[0]->GetName()));
		AMyActorInteractable * currentActor = ArrayOfActorsInteractable[0];
		if(currentActor->Implements<UInteractableInterface>())
		{
			currentActor->Execute_Interact(currentActor);
			RemoveActorInteractable(currentActor);
		}
	}
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

