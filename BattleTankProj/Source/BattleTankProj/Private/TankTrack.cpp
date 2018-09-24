// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();

	UE_LOG(LogTemp, Warning, TEXT("%s Throttling at %f"), *Name, Throttle);

	// TODO clamp actual throttle value so player can't overdrive
}