// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // paste new classes above this

//forward declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;


UCLASS()
class BATTLETANKPROJ_API ATank : public APawn
{
	GENERATED_BODY()

public:
	

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected: // can't be proviate because we will need to access it using a UProperty later
	
	
private:
	// Sets default values for this pawn's properties
	ATank();		

	virtual void BeginPlay() override;

	// TODO remove once firing is moved to aiming
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 4000; // 1000 m/s because units are centimeters

	UPROPERTY(EditAnywhere, Category = "Firing")
		float FireReloadTimeInSeconds = 3;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;


	double LastFireTime = 0;
	
};
