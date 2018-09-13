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
		// UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		// TODO tell controlled tank to aim at this point
	}
	
}

// Get world location of linetrace in this method (through crosshair), true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// find the cross hair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	//ideally designer will specify on tank controller bp where the crosshair is
	//we don't need to read the position of the dot from the widget interface. 
	//we need to get the screen location is based on the view port size (FVector2D)
	// we multiply because:
	// say the ViewPortSizeX is 1280, then we'll get (1280 * .5) for the x portion
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY  * CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());

	// "de-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
		UE_LOG(LogTemp, Warning, TEXT("Screen Look Direction: %s"), *LookDirection.ToString());

	// line trace along the direction (look direction), and see what we hit
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const 
{
	FVector CamWorldLoc;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CamWorldLoc, LookDirection);
}

