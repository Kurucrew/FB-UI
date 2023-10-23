// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "PlayerHPBar.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UPlayerHPBar : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> NowHP;

	int NowHPNUm = 0;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> MaxHP;

	int MaxHPNum = 0;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> NowEP;

	int NowEPNUm = 0;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> MaxEP;

	int MaxEPNum = 0;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> EPPercent;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UProgressBar> HPPercent;


public:

	UFUNCTION()
	void SetNowHP(float hp);

	UFUNCTION(BlueprintCallable)
	void SetMaxHP(float hp);

	UFUNCTION()
	void SetHPPercent(float hpp);

	UFUNCTION()
		void SetNowEP(float ep);

	UFUNCTION(BlueprintCallable)
		void SetMaxEP(float ep);

	UFUNCTION()
		void SetEPPercent(float epp);
};
