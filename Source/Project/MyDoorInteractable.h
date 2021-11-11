// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActorInteractable.h"
#include "Components/BoxComponent.h"

#include "MyDoorInteractable.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AMyDoorInteractable : public AMyActorInteractable
{
	GENERATED_BODY()
	public:
	AMyDoorInteractable();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent * StaticMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent * BoxComponent;
	protected:


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector OpenedOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector ClosedOffset;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsOpened;
	
	public:
	virtual void BeginPlay() override;
	virtual  void Tick(float DeltaSeconds) override;
	void Interact_Implementation();
};
