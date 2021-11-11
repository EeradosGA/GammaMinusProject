// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorInteractable.h"

// Sets default values
AMyActorInteractable::AMyActorInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bIsBeingInteractWith = false;
}

// Called when the game starts or when spawned
void AMyActorInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActorInteractable::Interact_Implementation()
{
	//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Magenta, "Interact implementation from AMyActorInteractable");
	if(	bIsBeingInteractWith == false)
	{
		bIsBeingInteractWith = true;
		//GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Magenta, "Is being interacted set to true ");
	}
}

