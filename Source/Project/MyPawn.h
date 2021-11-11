// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MyActorInteractable.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"

#include "MyPawn.generated.h"

class USphereComponent;
UCLASS()
class PROJECT_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	UCameraComponent * Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	USpringArmComponent * SpringArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	USkeletalMeshComponent * SkeletalMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	UCapsuleComponent * Capsule;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	UCapsuleComponent * SphereDetectionInteraction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pawn")
	UFloatingPawnMovement * FloatingPawnMovement;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
	TArray< AMyActorInteractable *> ArrayOfActorsInteractable;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray< AMyActorInteractable *> InventoryOfActorsInteractable;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn")
	float SpeedAnim;

public:
	UFUNCTION(BlueprintCallable, Category = "Interaction")
    TArray<AMyActorInteractable *> GetArrayOfActorInteractable()const  {return ArrayOfActorsInteractable;}
	UFUNCTION(BlueprintCallable, Category = "Interaction")
    void AddActorInteractable(AMyActorInteractable * _targetActor){ArrayOfActorsInteractable.AddUnique(_targetActor);}
	UFUNCTION(BlueprintCallable, Category = "Interaction")
    void RemoveActorInteractable(AMyActorInteractable * _targetActor);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
    TArray<AMyActorInteractable *> GetInventoryActorInteractable()const  {return InventoryOfActorsInteractable;}
	UFUNCTION(BlueprintCallable, Category = "Inventory")
    void AddActorInteractableToInventory(AMyActorInteractable * _targetActor){InventoryOfActorsInteractable.AddUnique(_targetActor);}
	UFUNCTION(BlueprintCallable, Category = "Inventory")
    void RemoveActorInteractableFromInventory(AMyActorInteractable * _targetActor);
	UFUNCTION(BlueprintCallable, Category = "Pawn")
	float GetSpeedAnim()const {return SpeedAnim;}

	void Interact();
	void SetSpeedAnim(float _value){SpeedAnim = _value ;}
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
