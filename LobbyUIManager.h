// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerProfile.h"
#include "ProfileScreen.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "MatchingButton.h"
#include "MatchingAsk.h"
#include "CharacterSelectScreen.h"
#include "CraftScreen.h"
#include "LobbyUIManager.generated.h"

/**
 * 
 */
enum Lobbynum
{
	Main,
	Profile,
	Costume,
	Inventory,
	CharacterSelect,
	Craft,
};

UCLASS()
class PROJECTFB_API ULobbyUIManager : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;
	virtual void NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent) override;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UPlayerProfile> m_PlayerProfile;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UWidgetSwitcher> LobbySwitcher;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite, meta = (AllowPrivateAccess = true))
		TObjectPtr<UProfileScreen> m_ProfileScreen;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCharacterSelectScreen> m_CharacterSelectScreen;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCraftScreen> m_CraftScreen;

	UPROPERTY()
		TObjectPtr<UButton> m_ProfileButton;

	UPROPERTY()
		TObjectPtr<UButton> m_CostumeButton;

	UPROPERTY()
		TObjectPtr<UButton> m_InventoryButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UMatchingButton> m_MatchingButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UMatchingAsk> m_MatchingAsk;

public:

	UFUNCTION()
		void OpenProfile();

	UFUNCTION()
		void OpenCostume();

	UFUNCTION()
		void OpenInventory();

	UFUNCTION()
		UMatchingButton* GetMatchingButton();

	UFUNCTION()
		UMatchingAsk* GetMatchingAsk();

	UFUNCTION()
		void ShowMatchingConfirm();

	UFUNCTION()
		void OpenPickScreen();

	UFUNCTION()
		UCharacterSelectScreen* GetSelectScreen();

	UFUNCTION()
		UWidgetSwitcher* GetLobbySwitcher();

	UFUNCTION()
		UCraftScreen* GetCraftScreen();

	UFUNCTION()
		void OpenCraftScreen();

};
