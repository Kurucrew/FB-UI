// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameCharacterSelectButton.h"
#include "CharacterSelectScreen.h"
#include "Game/FBGameInstance.h"
#include "Controller/ServerController/LobbyController.h"


void UInGameCharacterSelectButton::NativeOnInitialized()
{
	SelectButton->OnClicked.AddDynamic(this, &UInGameCharacterSelectButton::CharacterSelect);
}

void UInGameCharacterSelectButton::InitSelectButton(FCharacterInfo profile)
{

	SelectButton->WidgetStyle.Normal.SetResourceObject(profile.texture);
	SelectButton->WidgetStyle.Hovered.SetResourceObject(profile.texture);
	SelectButton->WidgetStyle.Pressed.SetResourceObject(profile.texture);
	CharacterName->SetText(profile.name);
	ButtonID = profile.name.ToString();

	CharacterBP = profile.CharacterBP;
}

void UInGameCharacterSelectButton::CharacterSelect()
{
	GetGameInstance<UFBGameInstance>()->SetSelectedCharacter(CharacterBP);
	GetWorld()->GetFirstPlayerController<ALobbyController>()->SetMyPawnClass(CharacterBP);
	SelectClickedDelegate.Broadcast(this);
}

void UInGameCharacterSelectButton::SetSelectedPlayer(FString name)
{
	OwnerID = name;
	SelectedPlayer->SetText(FText::FromString(name));
}

UBorder* UInGameCharacterSelectButton::GetPlayerBorder()
{
	return PlayerBorder;
}
