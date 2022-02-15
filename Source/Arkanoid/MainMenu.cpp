// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "ArkanoidGameModeBase.h"

bool UMainMenu::Initialize()
{
	Super::Initialize();

	PlayButton->OnReleased.AddDynamic(this, &UMainMenu::PlayGame);
	return true;
}

void UMainMenu::PlayGame()
{
	Cast<AArkanoidGameModeBase>(GetWorld()->GetAuthGameMode())->OpenPlaybleLevel();
}
