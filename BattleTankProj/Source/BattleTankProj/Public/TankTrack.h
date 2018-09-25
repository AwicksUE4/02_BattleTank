// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKPROJ_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public: 
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// max force per track, in Newtons
	// Force = Mass * accelerations
	// SI Units (force in newtons), (mass in kilograms), (accelerations in meters/sec
	// get wi/in a factor of 10
	UPROPERTY(EditDefaultsOnly)
	float MaxTrackDrivingForce = 40000000; // assume 40 tons tanks and 1g acceleration -> 400,000 newtowwns

};
