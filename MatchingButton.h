// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "MatchingButton.generated.h"

/**
 * 
 */
enum MatchState
{
	End,
	Start,
};

UCLASS()
class PROJECTFB_API UMatchingButton : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite, meta = (AllowPrivateAccess = true))
		TObjectPtr<UButton> MatchButton;
	
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> MatchingTime;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UWidgetSwitcher> m_Switcher;

	MatchState State = End;

	UPROPERTY()
		FTimerHandle Timer;

	UPROPERTY()
		FDateTime TimerStart;

	UFUNCTION()
		void StartTimer();

public:

	UFUNCTION()
		void Matching();

	UFUNCTION()
		void MatchingCancle();

};
