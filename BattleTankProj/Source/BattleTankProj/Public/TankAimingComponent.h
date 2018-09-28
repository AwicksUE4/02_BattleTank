// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading, 
	Aiming, 
	Locked
};

//Forward Declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;

// Holds barrel's properties and evelate metho
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKPROJ_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected: // we are trying to access this property from a subclass so it needs to be protected
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Locked;
	

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 4000; // 1000 m/s because units are centimeters

	UPROPERTY(EditAnywhere, Category = "Firing")
	float FireReloadTimeInSeconds = 3;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	double LastFireTime = 0;
};
