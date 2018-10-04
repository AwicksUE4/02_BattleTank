// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankAIController.h"
#include "Engine/World.h"
#include "../Public/TankAimingComponent.h"
// depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/*auto ControlledTank = Cast<ATank>(GetPawn());
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not posessing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Aicontroller is posessing %s"), *(ControlledTank->GetName()));
	}*/
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }		

	MoveToActor(PlayerTank, AcceptanceRadius); // TODO Check radius is in cm

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(AimingComponent)) { return; }

	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// if locked, then fire
	if (AimingComponent->GetFiringState() == EFiringState::Locked)
		AimingComponent->Fire();
}

