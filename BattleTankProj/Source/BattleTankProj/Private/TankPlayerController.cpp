// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	//this will return the pawn the player controller is currently possesing
	return Cast<ATank>(GetPawn());

}


