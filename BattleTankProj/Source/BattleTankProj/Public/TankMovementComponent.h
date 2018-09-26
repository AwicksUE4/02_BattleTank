// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


/**
 * Responsible foor driving the tank tracks
 */
class UTankTrack;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)) // we make this spawnable so that we can add the Tank Movement Component manually
class BATTLETANKPROJ_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Input")
	//will communicate the movement desired
	//throw - control throw - how far forward or back the control is moved
	void IntendMoveForward(float Throw);
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float Throw);
	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet); //public because we need to call it from the blueprint
	
private: 
	// called from the pathfinding logic by the ai controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
