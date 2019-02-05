// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move Barrel towrds new direction
	//With a max elevation speed and fram time
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Barrel-Elevate() moved at mach %f"), Time, RelativeSpeed);
}
