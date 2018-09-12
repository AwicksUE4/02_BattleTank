// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto Tank = GetControlledTank();

	if (!Tank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possessing a tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller posessing %sk"), (*Tank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play"));
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}