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

UENUM()
enum class EAmmoState :uint8
{
	Loaded,
	Out_Of_Ammo
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class METALABYSS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Barrel_Reloading;
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EAmmoState AmmoState = EAmmoState::Loaded;
public:
	// Sets default values for this component's properties

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();
	UFUNCTION(BlueprintCallable, Category = "Firing")
		int32 GetAmmo() const;
	void AimAt(FVector HitLocation);
	bool IsBarrelMoving();
	EFiringState GetFiringState() const;
	EAmmoState GetAmmoState() const;
	
private:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	FVector SavedAimDirection;
	UTankAimingComponent();
	void MoveBarrelTowards(FVector AimDirection);
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 100000; // Good value to begin with, 1000 m/s
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		int32 ammo = 10;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;
	double LastFireTime = 0;
	
};
