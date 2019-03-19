// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;
class AProjectile;
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


UCLASS()
class METALABYSS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	

	UFUNCTION(BlueprintCallable, Category = firing)
		void Fire();

protected:
	 UPROPERTY(BlueprintReadOnly)
		 UTankAimingComponent * TankAimingComponent = nullptr;
	 //UPROPERTY(BlueprintReadOnly)
	//	 UTankMovementComponent* TankMovementComponent = nullptr;
	
private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;
	// Called when the game starts or when spawned

	// Called to bind functionality to input

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 100000; // Good value to begin with, 1000 m/s

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;
	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;
	
	double LastFireTime = 0;
};

