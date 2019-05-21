// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
*
*/
UCLASS()
class METALABYSS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	//Put in protected because blueprint class is child to this C++ class
	UPROPERTY(EditAnywhere, Category = "Setup")
		float AcceptanceRadius = 8000; // 80 metres
	
private:

	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
		void OnPossessedTankDeath();
};
