// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArkanoidGameModeBase.h"
#include "Ball.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Paddle.generated.h"

UCLASS()

class ARKANOID_API APaddle : public APawn
{
	GENERATED_BODY()
	
	DECLARE_DELEGATE_OneParam(FIndexDelegate, const int32);
	DECLARE_DELEGATE_OneParam(FOrientationDelegate, const bool);

private:
	ABall* Ball;

	bool BallLaunched{false};

	bool Horizontal{true};
	
	TArray<AActor*> Positions;
	
	void MovePaddle(float Axis);

	void StartGame();

	void SwitchPosition(int I);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Construction")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Construction")
	UFloatingPawnMovement* PawnMovement;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABall> SpawnedActor;

	AArkanoidGameModeBase* GameMode;

public:
	APaddle();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	ABall* Ball1() const
	{
		return Ball;
	}
};
