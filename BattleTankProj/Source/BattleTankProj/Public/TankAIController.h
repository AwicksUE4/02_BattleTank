// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANKPROJ_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 3000;
};
