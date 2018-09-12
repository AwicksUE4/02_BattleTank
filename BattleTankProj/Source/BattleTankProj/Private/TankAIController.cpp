// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"
#include "Engine/World.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto Tank = GetPlayerTank();

	if (!Tank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller can't find player tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found palyer %s"), (*Tank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!PlayerPawn) { return nullptr; } 
	
	return Cast<ATank>(PlayerPawn);
}