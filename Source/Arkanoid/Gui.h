// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Gui.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API UGui : public UUserWidget
{
	GENERATED_BODY()


protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* PointsText;


	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	UTextBlock* PointsNum;

public:
	void SetPointsNum(const int32 Num)
	{
		const FString S_Num = FString::FromInt(Num);
		PointsNum->SetText(FText::FromString(S_Num));
	}
};
