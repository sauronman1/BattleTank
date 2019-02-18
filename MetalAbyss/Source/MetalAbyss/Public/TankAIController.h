// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
class ATank;
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
private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:

};
