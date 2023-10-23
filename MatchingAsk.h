// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"
#include "MatchingAsk.generated.h"

/**
 * 
 */
UENUM()
enum EMatchingState
{
	Idle,
	Accept,
};

UCLASS()
class PROJECTFB_API UMatchingAsk : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> YButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> NButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UWidgetSwitcher> MatchingSwitcher;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> Readyusers;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> Maxusers;

	UFUNCTION()
		void MatchingAccept();

	UFUNCTION()
		void MatchingCancle();

public:

	EMatchingState state = Idle;

	UFUNCTION()
		void PlayerCount(int32 n, int32 m);

	UFUNCTION()
		void SwitcherDefault();

};
