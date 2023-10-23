// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetSwitcher.h"
#include "PlayerHPBar.h"
#include "OccupationBar.h"
#include "PlayerDie.h"
#include "PlayerPortrait.h"
#include "AbilitySelector.h"
#include "GameEnd.h"
#include "TeamInfoPanel.h"
#include "PlayerUIManager.generated.h"

/**
 * 
 */
enum WigetIndex
{
	MainUI,
	PlayerDie,
	LoadingScreen,
	GameEnd,
};

UCLASS()
class PROJECTFB_API UPlayerUIManager : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> m_WidgetSwitcher;

	/*UPROPERTY(meta = (BindWidget))
	TObjectPtr<UPlayerHPBar> m_PlayerHPBar;*/

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UOccupationBar> m_OccupationBar;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UPlayerDie> m_PlayerDie;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UUserWidget> m_WaitingOtherPlayer;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UPlayerPortrait> m_PlayerPortrait;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UAbilitySelector> m_AbilitySelector;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	TObjectPtr<UWidgetAnimation> SelectorMove;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UGameEnd> m_GameEnd;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTeamInfoPanel> m_TeamInfoPanel;

	UFUNCTION()
		void SelectorOnNOff();

	virtual void NativeOnInitialized() override;

public:
	/*UFUNCTION()
	UPlayerHPBar* GetPlayerHPBar();*/

	UFUNCTION()
	UOccupationBar* GetOccupationBar();

	UFUNCTION()
	UPlayerDie* GetPlayerDie();

	UFUNCTION()
	UWidgetSwitcher* GetWidgetSwitcher();

	UFUNCTION()
	UPlayerPortrait* GetPlayerPortrait();

	UFUNCTION()
	UAbilitySelector* GetAbilitySelector();

	UFUNCTION()
	UGameEnd* GetGameEnd();

	UFUNCTION()
		UTeamInfoPanel* GetTeamInfoPanel();
};
