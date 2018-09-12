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
	// we check becuz it makes no sense to check aim unless we are controlling a tank
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // out parameter
	if(GetSightRayHitLocation(HitLocation)) // has "side-effect", is going to line trace
	{	
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// TODO tell controlled tank to aim at this point
	}
	
}

// Get world location of linetrace in this method (through crosshair), true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;
}


