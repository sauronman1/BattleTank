// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class UTankAimingComponent;
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
*
*/
UCLASS()
class METALABYSS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);
	UFUNCTION()
		void OnPossessedTankDeath();
private:
	

	// Makes the tank start moving the barrel so that the shot would hit where
	// the crosshair intersects the world
	void SetPawn(APawn* InPawn);
	
	void AimTowardsCrosshair();

	// return an OUT parameter, true if it hits landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.3333;

};
