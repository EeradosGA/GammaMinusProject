// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDoorInteractable.h"

AMyDoorInteractable::AMyDoorInteractable()
{
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
    BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
    RootComponent = BoxComponent;
    StaticMeshComponent->SetupAttachment(RootComponent);
}

void AMyDoorInteractable::BeginPlay()
{
    Super::BeginPlay();
}

void AMyDoorInteractable::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Magenta, "Door tick");

    // if the door has been interacted with
    if(bIsBeingInteractWith == true)
    {
        //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Magenta, "Interact with door");

        // close the door if it is already open, or open it if it is already closed
        if(bIsOpened == true)
        {
            bIsOpened = false;
            bIsBeingInteractWith = false;
            AddActorLocalOffset(ClosedOffset);
            //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Magenta, "Closed !");
        }
        else
        {
            bIsOpened = true;
            bIsBeingInteractWith = false;
            AddActorLocalOffset(OpenedOffset);
            //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Magenta, "Opened !");
        }
    }
}

void AMyDoorInteractable::Interact_Implementation()
{
    //GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Magenta, "Interact implementation from MyDoorInteractable");
    AMyActorInteractable::Interact_Implementation();
}
