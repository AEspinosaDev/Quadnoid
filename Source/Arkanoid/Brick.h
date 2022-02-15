// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArkanoidGameModeBase.h"
#include "Booster.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"
UCLASS()
class ARKANOID_API ABrick : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Construction")
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Rotation Speed")
	float RotSpeed{0.5};

	UPROPERTY(EditAnywhere)
	TSubclassOf<ABooster> SpawnedBooster;

	UFUNCTION()
	void OnBallHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	               FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBrickDestruction();

	AArkanoidGameModeBase* GameMode;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void CreateBooster();
};

