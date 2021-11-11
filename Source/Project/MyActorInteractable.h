// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "InteractableInterface.h"
#include "GameFramework/Actor.h"
#include "MyActorInteractable.generated.h"

UCLASS()
class PROJECT_API AMyActorInteractable : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActorInteractable();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
    bool GetIsBeingInteractWith()const {return bIsBeingInteractWith;}
	UFUNCTION(BlueprintCallable, Category = "Interaction")
    void SetIsBeingInteractWith(bool _isBeingInteractWith) {bIsBeingInteractWith = _isBeingInteractWith;}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool bIsBeingInteractWith;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Interact_Implementation();
};
