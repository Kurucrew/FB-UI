// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "PlayerNameUI.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UPlayerNameUI : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> PlayerLevel;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		TObjectPtr<UProgressBar> PlayerHPBar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		TObjectPtr<UTextBlock> PlayerName;

public:
	UFUNCTION()
		void SetPlayerName(FText name);

	UFUNCTION()
		void SetPlayerLevel(int level);

	UFUNCTION()
		void SetPlayerHPBar(float hp, float maxhp);

};
