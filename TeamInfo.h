// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "TeamInfo.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UTeamInfo : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> Lvl;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> Nickname;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UProgressBar> HPBar;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UImage> Portrait;

public:

	UFUNCTION()
		void SetNickname(FString name);

	UFUNCTION()
		void SetLvl(int lv);

	UFUNCTION()
		void SetHPBar(float hpp);
	
};
