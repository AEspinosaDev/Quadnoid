// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

#include <dsound.h>

#include "ArkanoidGameModeBase.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

// Sets default values

ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Ball");
	Mesh->SetEnableGravity(false);
	Mesh->SetSimulatePhysics(false);
	Mesh->SetConstraintMode(EDOFMode::YZPlane);
	Mesh->SetNotifyRigidBodyCollision(true);
	Mesh->BodyInstance.SetCollisionProfileName("Projectile");

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Movement");
	MovementComponent->InitialSpeed = 0.0f;
	MovementComponent->UpdatedComponent = Mesh;
	MovementComponent->MaxSpeed = 1000.f;
	MovementComponent->bRotationFollowsVelocity = true;
	MovementComponent->bShouldBounce = true;
	MovementComponent->Bounciness = 1;
}

// Called when the game starts or when spawned

void ABall::BeginPlay()
{
	Super::BeginPlay();
	Mesh->OnComponentHit.AddDynamic(this, &ABall::Bounce);
}

void ABall::Bounce(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                   FVector NormalImpulse, const FHitResult& Hit)
{
	OnBounce();
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, "+10");
}


void ABall::FellOutOfWorld(const UDamageType& dmgType)
{
	// Super::FellOutOfWorld(dmgType);
	// if (!Lost)
	// {
	// 	Lost = true;
	// 	Cast<AArkanoidGameModeBase>(GetWorld()->GetAuthGameMode())->GameOver();
	// }
}

// Called every frame

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABall::Launch()
{
	MovementComponent->Velocity = FVector(0, FMath::RandRange(-1000, 1000), 1000);


	Launched = true;
}
