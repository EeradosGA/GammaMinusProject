// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MyPawn.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	AMyPlayerController();

	public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupInputComponent() override;
	protected:
	FVector direction;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AMyPawn * MyPawnRef;
	float TurnSpeed;
	float LookUpSpeed;
	float ViewBlendTime;
	bool bIsMovingToRight;
	bool bIsMovingForward;

	public:
	// Controller functions
	void MoveRight(float _value);
	void Turn(float _value);
	void MoveForward(float _value);
	void InteractInput();

};
