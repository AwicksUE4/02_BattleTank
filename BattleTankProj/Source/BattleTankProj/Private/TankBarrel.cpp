// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//move the barrel the right amount this frame -- 

	//given a max elevation speed and the frame time (we need to be frame rate independent)
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
	
}




