// Fill out your copyright notice in the Description page of Project Settings.
#include "../Public/TankPlayerController.h"
#include "Engine/World.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not posseing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing %s"), *(ControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	//this will return the pawn the player controller is currently possesing
	//should return the actual tank that's being possessed
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	AimTowardsCrossHair();

	UE_LOG(LogTemp, Warning, TEXT("I am ticking"));
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	// get world location through crosshair (line trace through crosshair)
	// if tis hits the landscape
		// tell controlled tank to aim at this point
}


