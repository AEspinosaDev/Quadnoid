// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Booster.generated.h"

UCLASS()
class ARKANOID_API ABooster : public AActor
{
	GENERATED_BODY()
	


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Setup")
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Setup")
	UProjectileMovementComponent* MovementComponent;
	

	virtual void BeginPlay() override;

public:	
	ABooster();
	virtual void Tick(float DeltaTime) override;
	void Launch(FVector Vec);
	
};
