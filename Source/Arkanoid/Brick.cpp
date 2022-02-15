// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"


#include "Ball.h"
#include "GameFramework/GameModeBase.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Brick");
	Mesh->SetSimulatePhysics(false);
	Mesh->SetEnableGravity(false);
	Mesh->SetNotifyRigidBodyCollision(true);

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AArkanoidGameModeBase>(GetWorld()->GetAuthGameMode());
	Mesh->OnComponentHit.AddDynamic(this, &ABrick::OnBallHit);
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &ABrick::CreateBooster, FMath::RandRange(1,20), false);

	
}

void ABrick::OnBallHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	//CreateBooster();
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, "+10");
	if(OtherActor->GetClass()->IsChildOf(ABall::StaticClass()))
	{
		GameMode->AddPoints(10);
		OnBrickDestruction();
		Destroy();	
	}
	
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Mesh->SetWorldRotation(FRotator(0,0,GetActorRotation().Roll+RotSpeed));

}

void ABrick::CreateBooster()
{
	ABooster* Booster = GetWorld()->SpawnActor<ABooster>(SpawnedBooster, FVector(GetActorLocation().X, GetActorLocation().Y,
															   GetActorLocation().Z + 10), GetActorRotation());
	Booster->Launch(Mesh->GetUpVector()*500);
	
}

