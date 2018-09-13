// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // paste new classes above this

UCLASS()
class BATTLETANKPROJ_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup) // method we can call from blueprint
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

protected: // can't be proviate because we will need to access it using a UProperty later
	UTankAimingComponent * TankAimingComponent = nullptr;
	

private:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Sets default values for this pawn's properties
	ATank();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000; // TODO find sensible default starting value of 1000 m/s because units are centimeters

	
	
};
