// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyUIManager.h"

void ULobbyUIManager::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	m_ProfileButton = m_PlayerProfile->GetProfileButton();
	m_ProfileButton->OnClicked.AddDynamic(this, &ULobbyUIManager::OpenProfile);

	m_CostumeButton = m_PlayerProfile->GetCostumeButton();
	m_CostumeButton->OnClicked.AddDynamic(this, &ULobbyUIManager::OpenCostume);

	m_InventoryButton = m_PlayerProfile->GetInventoryButton();
	m_InventoryButton->OnClicked.AddDynamic(this, &ULobbyUIManager::OpenInventory);

	GetWorld()->GetFirstPlayerController()->InputComponent->BindAction(TEXT("Crafting"), EInputEvent::IE_Pressed, this, &ULobbyUIManager::OpenCraftScreen);
}

void ULobbyUIManager::NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnRemovedFromFocusPath(InFocusEvent);

	//LobbySwitcher->SetActiveWidgetIndex(Main);
}

void ULobbyUIManager::OpenProfile()
{
	LobbySwitcher->SetActiveWidgetIndex(Profile);
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	m_PlayerProfile->PopUp();
}

void ULobbyUIManager::OpenCostume()
{
	LobbySwitcher->SetActiveWidgetIndex(Costume);
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	m_PlayerProfile->PopUp();
}

void ULobbyUIManager::OpenInventory()
{
	LobbySwitcher->SetActiveWidgetIndex(Inventory);
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
	m_PlayerProfile->PopUp();
}

UMatchingButton* ULobbyUIManager::GetMatchingButton()
{
	return m_MatchingButton;
}

UMatchingAsk* ULobbyUIManager::GetMatchingAsk()
{
	return m_MatchingAsk;
}

void ULobbyUIManager::ShowMatchingConfirm()
{
	m_MatchingAsk->SetVisibility(ESlateVisibility::Visible);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetGameViewport()->SetMouseCaptureMode(EMouseCaptureMode::NoCapture);
}

void ULobbyUIManager::OpenPickScreen()
{
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetGameViewport()->SetMouseCaptureMode(EMouseCaptureMode::NoCapture);
	LobbySwitcher->SetActiveWidgetIndex(CharacterSelect);
}

UCharacterSelectScreen* ULobbyUIManager::GetSelectScreen()
{
	return m_CharacterSelectScreen;
}

UWidgetSwitcher* ULobbyUIManager::GetLobbySwitcher()
{
	return LobbySwitcher;
}

UCraftScreen* ULobbyUIManager::GetCraftScreen()
{
	return m_CraftScreen;
}

void ULobbyUIManager::OpenCraftScreen()
{
	LobbySwitcher->SetActiveWidgetIndex(Craft);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetGameViewport()->SetMouseCaptureMode(EMouseCaptureMode::NoCapture);
}
