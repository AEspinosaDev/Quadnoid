// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathVolume.h"

#include "ArkanoidGameModeBase.h"
#include "Ball.h"
#define PRINT_TO_VIEWPORT(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String);

ADeathVolume::ADeathVolume()
{
}

void ADeathVolume::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ADeathVolume::BeginOverLap);
	//OnActorHit.AddDynamic(this, &ADeathVolume::OnHit);
}

void ADeathVolume::BeginOverLap(AActor* OverlappedActor, AActor* OtherActor)
{
	OverlappedActor->Destroy();
	if (OtherActor->GetClass()->IsChildOf(ABall::StaticClass()))
	{
		PRINT_TO_VIEWPORT("la bola xD");
		Cast<AArkanoidGameModeBase>(GetWorld()->GetAuthGameMode())->GameOver();
		OtherActor->Destroy();
	}
}

void ADeathVolume::OnHit(AActor* Actor, AActor* OtherActor,
                         FVector NormalImpulse, const FHitResult& Hit)
{
	PRINT_TO_VIEWPORT("jaja");
	OtherActor->Destroy();
	//Actor->Destroy();
}
