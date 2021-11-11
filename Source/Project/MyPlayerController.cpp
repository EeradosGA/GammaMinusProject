// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
    TurnSpeed = 150.0f;
    bIsMovingToRight = false;
    bIsMovingForward = false;
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();
    MyPawnRef = Cast<AMyPawn>(GetPawn());

}

void AMyPlayerController::Tick(float DeltaSeconds)
{
    if(bIsMovingForward == false && bIsMovingToRight == false)
    {
        MyPawnRef->SetSpeedAnim(0);
    }
    else//(bIsMovingForward == true || bIsMovingToRight == true)
    {
        MyPawnRef->SetSpeedAnim(350);
    }

}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    check(InputComponent);
    
    InputComponent->BindAxis(TEXT("MoveForward"), this, &AMyPlayerController::MoveForward);
    InputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPlayerController::MoveRight);
    InputComponent->BindAxis(TEXT("Turn"), this, &AMyPlayerController::Turn);
    InputComponent->BindAction(TEXT("Interact"), IE_Pressed, this, &AMyPlayerController::InteractInput);

}

void AMyPlayerController::MoveRight(float _value)
{
    if(MyPawnRef == nullptr)
        return;
   
    
    const FRotator pawnRot = GetControlRotation();
    const FRotator yawRot(0, pawnRot.Yaw, 0);
    const FVector dir = FRotationMatrix(yawRot).GetScaledAxis(EAxis::Y);
    MyPawnRef->AddMovementInput(dir, _value);

    MyPawnRef->SetActorRotation(GetControlRotation());
    if(_value != 0)
    {
        bIsMovingToRight = true;
    }
    else
    {
        bIsMovingToRight = false;
    }
}


void AMyPlayerController::Turn(float _value)
{
    if(MyPawnRef == nullptr)
        return;
    
    MyPawnRef->AddControllerYawInput(_value * GetWorld()->GetDeltaSeconds() * TurnSpeed);
}

void AMyPlayerController::MoveForward(float _value)
{
    if(MyPawnRef == nullptr)
        return;

    
    const FRotator pawnRot = GetControlRotation();
    const FRotator yawRot(0, pawnRot.Yaw, 0);
    const FVector dir = FRotationMatrix(yawRot).GetScaledAxis(EAxis::X);
    MyPawnRef->AddMovementInput(dir, _value);
    if(_value != 0)
    {
        bIsMovingForward = true;
    }
    else
    {
        bIsMovingForward = false;
    }
}

void AMyPlayerController::InteractInput()
{
    if(MyPawnRef == nullptr)
        return;
    
    Cast<AMyPawn>(MyPawnRef)->Interact();
}
