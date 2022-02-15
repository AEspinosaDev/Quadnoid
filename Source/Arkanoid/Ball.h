// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Ball.generated.h"

UCLASS()
class ARKANOID_API ABall : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Construction")
	UStaticMeshComponent* Mesh;

	FVector Direction{FVector(0, 0, 1)};
	
	bool Launched{false};

	bool Lost{false};
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Construction")
	UProjectileMovementComponent* MovementComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void Bounce(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBounce();
	
	virtual void FellOutOfWorld(const UDamageType& dmgType) override;
public:
	ABall();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void Launch();

	
};
