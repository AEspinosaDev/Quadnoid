// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Gui.h"
#include "MainMenu.h"
#include "GameFramework/GameModeBase.h"
#include "ArkanoidGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AArkanoidGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
private:
	int32 Points{0};
	APlayerController* Controller;

	TArray<FString> Levels;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UMG")
	TSubclassOf<UMainMenu> MainMenuRef;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UMG")
	UMainMenu* MainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UMG")
	TSubclassOf<UGui> GuiRef;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UMG")
	UGui* Gui;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UMG")
	TSubclassOf<UUserWidget> PauseRef;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UMG")
	UUserWidget* Pause;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UMG")
	TSubclassOf<UUserWidget> EndGameRef;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UMG")
	UUserWidget* EndGame;


public:
	AArkanoidGameModeBase()
	{
	}

	virtual void BeginPlay() override;

	void GameOver();

	void AddPoints(int32 pts);

	void OpenPlaybleLevel();
	void OpenPlaybleLevelAux();

	void OpenMainMenu();

	APlayerController* Controller1() const
	{
		return Controller;
	}
};
