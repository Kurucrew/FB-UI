// Fill out your copyright notice in the Description page of Project Settings.


#include "ProfileScreen.h"
#include "LobbyUIManager.h"
#include "Controller/ServerController/LobbyController.h"

void UProfileScreen::NativeOnInitialized()
{
	CloseButton->OnClicked.AddDynamic(this, &UProfileScreen::CloseWidget);
	CharacterInfoButton->OnClicked.AddDynamic(this, &UProfileScreen::SwitchToInfo);
	PlayerStatButton->OnClicked.AddDynamic(this, &UProfileScreen::SwitchToStat);
}

void UProfileScreen::CloseWidget()
{
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	GetWorld()->GetFirstPlayerController<ALobbyController>()->GoToMainScreen();
}

void UProfileScreen::SwitchToInfo()
{
	ProfileSwitcher->SetActiveWidgetIndex(Profilenum::Info);
}

void UProfileScreen::SwitchToStat()
{
	ProfileSwitcher->SetActiveWidgetIndex(Profilenum::Stat);
}

UCharacterInfoScreen* UProfileScreen::GetCharacterInfoScreen()
{
	return m_CharacterInfoScreen;
}

UPlayerStatScreen* UProfileScreen::GetPlayerStatScreen()
{
	return m_PlayerStatScreen;
}

