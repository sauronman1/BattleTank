// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class UTankBarrel;
class UTankTurret;
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
	// Called every frame
	void AimAt(FVector HitLocation, float LaunchSpeed);
	
private:

	UTankAimingComponent();

	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};
