// Fill out your copyright notice in the Description page of Project Settings.


#include "Booster.h"

// Sets default values
ABooster::ABooster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
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
void ABooster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABooster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABooster::Launch(FVector Vec)
{
	MovementComponent->Velocity = Vec;
}


