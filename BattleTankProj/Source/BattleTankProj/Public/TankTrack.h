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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public: 
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	// max force per track, in Newtons
	// Force = Mass * accelerations
	// SI Units (force in newtons), (mass in kilograms), (accelerations in meters/sec
	// get wi/in a factor of 10
	UPROPERTY(EditDefaultsOnly)
	float MaxTrackDrivingForce = 40000000; // assume 40 tons tanks and 1g acceleration -> 400,000 newtowwns

private:
	UTankTrack();	

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	

};
