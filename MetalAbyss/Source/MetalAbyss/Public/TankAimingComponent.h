// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class UTankBarrel;
class UTankTurret;
class AProjectile;
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState :uint8
{
	Barrel_Aiming,
	Barrel_Reloading,
	Barrel_Locked
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class METALABYSS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Barrel_Locked;
public:
	// Sets default values for this component's properties

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = firing)
		void Fire();
	void AimAt(FVector HitLocation);
	
	
private:

	UTankAimingComponent();
	void MoveBarrelTowards(FVector AimDirection);
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 100000; // Good value to begin with, 1000 m/s
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;
	double LastFireTime = 0;
};
