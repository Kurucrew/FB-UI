// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "PlayerPortrait.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UPlayerPortrait : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UImage> PortraitImage;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> PlayerLevel;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UProgressBar> PlayerExpBar;

public:

	UFUNCTION()
		void SetPlayerLevel(int lv);

	UFUNCTION()
		void SetPlayerExpBar(float exp, float maxexp);
};
