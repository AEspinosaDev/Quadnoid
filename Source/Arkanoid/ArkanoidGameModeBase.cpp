// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArkanoidGameModeBase.h"
#include "Paddle.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void AArkanoidGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//Input mode setup
	Controller = GetWorld()->GetFirstPlayerController();
	FInputModeUIOnly InputModeUIOnly;
	Controller->SetShowMouseCursor(true);
	Controller->SetInputMode(InputModeUIOnly);
	//Camera setup
	TArray<AActor*> Cameras;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),ACameraActor::StaticClass(),Cameras);
	Controller->SetViewTarget(Cameras[1]);
	//WidgetCreation
	Gui = CreateWidget<UGui>(GetWorld(),GuiRef);
	EndGame = CreateWidget<UUserWidget>(GetWorld(),EndGameRef);
	MainMenu = CreateWidget<UMainMenu>(GetWorld(),MainMenuRef);
	MainMenu->AddToViewport();
	
	
}

void AArkanoidGameModeBase::GameOver()
{
	FInputModeUIOnly InputModeUIOnly;
	Controller->SetInputMode(InputModeUIOnly);
	Controller->SetShowMouseCursor(true);
	Gui->RemoveFromViewport();
	EndGame->AddToViewport();
}


void AArkanoidGameModeBase::AddPoints(int32 pts)
{
	Points+=pts;
	Gui->SetPointsNum(Points);
}

void AArkanoidGameModeBase::OpenPlaybleLevel()
{

	//UGameplayStatics::OpenLevel(this,"Level_1",true);
	
	
	MainMenu->RemoveFromViewport();
	
	TArray<AActor*> Cameras;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),ACameraActor::StaticClass(),Cameras);
	Controller->SetViewTargetWithBlend(Cameras[0],5,VTBlend_EaseInOut,2);

	//Wait for the camera to be in position
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(
		UnusedHandle, this, &AArkanoidGameModeBase::OpenPlaybleLevelAux, 5, false);

	
	
}

void AArkanoidGameModeBase::OpenPlaybleLevelAux()
{
	//Input Setup
	FInputModeGameOnly InputModeGameOnly;
	Controller->SetInputMode(InputModeGameOnly);
	Controller->SetShowMouseCursor(false);
	Gui->AddToViewport();
}

