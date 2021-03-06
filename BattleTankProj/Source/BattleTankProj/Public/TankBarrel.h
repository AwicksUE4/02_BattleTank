// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANKPROJ_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	// -1 is max downware speed, and +1 is max up movement. Will clamp down the value
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category= "Setup")
		float MaxDegreesPerSecond = 10;
	
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxElevation = 40;
	
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MinElevation = 0;
};
