// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* PlayButton;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* ExitButton;
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UButton* OptionsButton;

	UFUNCTION()
	void PlayGame();

	virtual bool Initialize() override;
	
};
