// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "UIStruct.h"
#include "CharacterInfoScreen.h"
#include "PlayerStatScreen.h"
#include "ProfileScreen.generated.h"

/**
 * 
 */

enum Profilenum
{
	Info,
	Stat,
};

UCLASS()
class PROJECTFB_API UProfileScreen : public UUserWidget
{
	GENERATED_BODY()

		virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> CloseButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> CharacterInfoButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> PlayerStatButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UWidgetSwitcher> ProfileSwitcher;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCharacterInfoScreen> m_CharacterInfoScreen;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UPlayerStatScreen> m_PlayerStatScreen;

	UFUNCTION()
		void CloseWidget();

	UFUNCTION()
		void SwitchToInfo();

	UFUNCTION()
		void SwitchToStat();

	UFUNCTION()
		UCharacterInfoScreen* GetCharacterInfoScreen();

	UFUNCTION()
		UPlayerStatScreen* GetPlayerStatScreen();
};
