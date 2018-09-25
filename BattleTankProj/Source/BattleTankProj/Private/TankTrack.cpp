// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * MaxTrackDrivingForce;
	auto ForceLocation = GetComponentLocation();
	// want to add a force to the root component (which is the tank)
	// a static mesh component is also a USceneComponent
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}