// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class UTankTrack;
#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class METALABYSS_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = input)
		void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = input)
		void IntendTurnRight(float Throw);
	UFUNCTION(BlueprintCallable, Category = Input)
		void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);
private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
};
