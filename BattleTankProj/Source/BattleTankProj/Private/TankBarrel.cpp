// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	//move the barrel the right amount this frame -- 

	//given a max elevation speed and the frame time (we need to be frame rate independent)

	UE_LOG(LogTemp, Warning, TEXT("Barrel-Elevate() called at speed %f"), DegreesPerSecond);
}




