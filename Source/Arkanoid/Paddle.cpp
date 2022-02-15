// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"

#include "Ball.h"
#include "Editor.h"
#include "Camera/CameraActor.h"
#include "Engine/TargetPoint.h"
#include "Kismet/GameplayStatics.h"


// Sets default values

// Called when the game starts or when spawned
APaddle::APaddle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Paddle");
	RootComponent = Mesh;
	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
	Mesh->SetConstraintMode(EDOFMode::YZPlane);
	Mesh->SetSimulatePhysics(false);
	Mesh->SetEnableGravity(false);
	//Mesh->SetWorldScale3D(FVector(0.5,0.5,0.5));
}

void APaddle::BeginPlay()
{
	Super::BeginPlay();

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	GameMode = Cast<AArkanoidGameModeBase>(GetWorld()->GetAuthGameMode());

	Ball = GetWorld()->SpawnActor<ABall>(SpawnedActor, FVector(GetActorLocation().X, GetActorLocation().Y,
	                                                           GetActorLocation().Z + 50), GetActorRotation());
	Ball->SetActorScale3D(FVector(0.11, 0.11, 0.11));
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Positions);
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (BallLaunched == false)
	{
		Ball->SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y,
		                               GetActorLocation().Z + 50));
	}
}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MovePaddle", this, &APaddle::MovePaddle);
	// PlayerInputComponent->BindAxis("MovePaddle", this, &APaddle::MovePaddle);
	PlayerInputComponent->BindKey(EKeys::SpaceBar, IE_Released, this, &APaddle::StartGame);
	PlayerInputComponent->BindAction<FIndexDelegate>("Left", IE_Released, this, &APaddle::SwitchPosition, 1);
	PlayerInputComponent->BindAction<FIndexDelegate>("Right", IE_Released, this, &APaddle::SwitchPosition, 2);
	PlayerInputComponent->BindAction<FIndexDelegate>("Top", IE_Released, this, &APaddle::SwitchPosition, 3);
	PlayerInputComponent->BindAction<FIndexDelegate>("Bottom", IE_Released, this, &APaddle::SwitchPosition, 4);
}

void APaddle::MovePaddle(float Axis)
{
	if(Horizontal) AddMovementInput(FVector(0.0f, Axis, 0.0f), 1, false);
	else AddMovementInput(FVector(0.0f, 0.0f, Axis), 1, false);
}

void APaddle::StartGame()
{
	if (BallLaunched == false)
	{
		BallLaunched = true;
		Ball->Launch();
	}
}

void APaddle::SwitchPosition(int I)
{
	switch (I)
	{
	case 1:
		Horizontal=false;
		SetActorLocation(Positions[0]->GetActorLocation());
		Mesh->SetWorldRotation(FRotator(0,0,90));
		break;
	case 2:
		Horizontal=false;
		SetActorLocation(Positions[1]->GetActorLocation());
		Mesh->SetWorldRotation(FRotator(0,0,-90));
		break;
	case 3:
		Horizontal=true;
		SetActorLocation(Positions[2]->GetActorLocation());
		Mesh->SetWorldRotation(FRotator(0,0,180));
		break;
	case 4:
		Horizontal=true;
		SetActorLocation(Positions[3]->GetActorLocation());
		Mesh->SetWorldRotation(FRotator(0,0,0));
		break;
	default:
		break;
	}
}
