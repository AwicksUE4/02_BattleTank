// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/Tank.h"
#include "../Public/TankAimingComponent.h"
#include "../Public/TankMovementComponent.h"
#include "Engine/World.h"
#include "../Public/TankBarrel.h"
#include "../Public/Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::Fire()
{
	bool isReloaded = FPlatformTime::Seconds() - LastFireTime > FireReloadTimeInSeconds;

	if (Barrel && isReloaded) 
	{
		//spawn a projectile at the socket location on the barrel
		auto SpawnLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto SpawnRotation = Barrel->GetSocketRotation(FName("Projectile"));

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, SpawnLocation, SpawnRotation);

		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

