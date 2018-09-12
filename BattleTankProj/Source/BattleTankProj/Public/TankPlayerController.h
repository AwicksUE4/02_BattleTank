// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

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
};
