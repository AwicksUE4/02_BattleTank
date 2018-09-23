// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKPROJ_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	ATank * GetControlledTank() const; //we aren't going to change any future member variables (const)

	virtual void BeginPlay() override; //ensure that this method exists up in the hierarchy

	virtual void PlayerTick(float DeltaTime) override;

	void AimTowardsCrossHair(); // not sonst because it is going to change something about the player controller's state

private:
	bool GetSightRayHitLocation(FVector& OutHitLocation) const; //const because it's not going to mutate any of the member functions of this class

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = .5f;
	
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = .33333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	bool GetLookVectorHitLocation(FVector& LookDirection, FVector& HitLocation) const;
};
