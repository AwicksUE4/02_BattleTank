// Fill out your copyright notice in the Description page of Project Settings.

#include "../Public/TankTrack.h"

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

	UE_LOG(LogTemp, Warning, TEXT("UTank Track BeginPlay"));
}


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	//OnComponentHit
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("I am hitting"));
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * MaxTrackDrivingForce;
	auto ForceLocation = GetComponentLocation();
	// want to add a force to the root component (which is the tank)
	// a static mesh component is also a USceneComponent
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//calculate the slippage speed (dot product)
	// the component of speed in the tank "right" direction, if no slippage, then value is zero, if sliding entirely, value should speed of tank, us cos of angle between velicyt of tank (direction its' goine ine) and slideways right vector
	// if it is going perfectly sideways, then the cosine between 2 angles is 1, if it's going forward, then angle is 90 degrees which means 
	//cosine is 0
	auto TankVelocity = GetComponentVelocity();
	auto TankRightV = GetRightVector();

	auto SlippageSpeed = FVector::DotProduct(TankVelocity, TankRightV);
	
	//work out the required acceleration this frame to correct (if we are moving sideways 10cm a second, then 
	//acceleration is speed over time, determine direction of acceleration
	//use the minus because we want to apply the acceleration in the opposite direction
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * TankRightV;

	//we will need a certain amount of accerlation to fix that velocity back down to zero sideways
	//calculate and apply sideways force (f = m * a)
	//the mass exist on the tank (which is a static mesh) so we have to cast
	// we divide by 2 because their are 2 tracks
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2;
	TankRoot->AddForce(CorrectionForce);
}