// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "DeathVolume.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API ADeathVolume : public ATriggerVolume
{
	GENERATED_BODY()


public:
	ADeathVolume();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void BeginOverLap(AActor* OverlappedActor,AActor* OtherActor );
	UFUNCTION()
	void OnHit(AActor* Actor, AActor* OtherActor,
	FVector NormalImpulse, const FHitResult& Hit);
	
};
