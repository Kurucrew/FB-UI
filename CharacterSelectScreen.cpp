// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSelectScreen.h"
#include "InGameCharacterSelectButton.h"
#include "Net/UnrealNetwork.h"
#include "Game/FBGameInstance.h"
#include "Game/FBGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Controller/ServerController/LobbyController.h"

void UCharacterSelectScreen::NativeOnInitialized()
{

	ReadyButton->OnClicked.AddDynamic(this, &UCharacterSelectScreen::ReadyToPlay);

	for (auto& iter : CharacterArray)
	{
		UInGameCharacterSelectButton* button = CreateWidget<UInGameCharacterSelectButton>(CharacterWrapBox, ButtonBP);

		button->InitSelectButton(iter);
		button->SelectClickedDelegate.AddDynamic(this, &UCharacterSelectScreen::CharacterSelected);
		SelecterArray.Add(button);
		CharacterWrapBox->AddChildToWrapBox(button);
	}
}

void UCharacterSelectScreen::SetTimerWidget(int time)
{
	TimeText->SetText(FText::AsNumber(time));
}

void UCharacterSelectScreen::ReadyToPlay()
{
	switch (ButtonState)
	{
	case Cancle:
		CharacterWrapBox->SetVisibility(ESlateVisibility::HitTestInvisible);
		ButtonText->SetText(FText::FromString("Cancle"));
		IsReady = true;
		GetWorld()->GetFirstPlayerController<ALobbyController>()->SendPickComplete();
		ButtonState = Ready;
		break;
	case Ready:
		CharacterWrapBox->SetVisibility(ESlateVisibility::Visible);
		ButtonText->SetText(FText::FromString("Ready"));
		IsReady = false;
		GetWorld()->GetFirstPlayerController<ALobbyController>()->SendPickCancel();
		ButtonState = Cancle;
		break;
	default:
		break;
	}

}

void UCharacterSelectScreen::CharacterSelected(class UInGameCharacterSelectButton* selected)
{
	IsSelected = true;
	GetWorld()->GetFirstPlayerController<ALobbyController>()->SendPickStatus(selected->ButtonID);
}

void UCharacterSelectScreen::RecvCharacterSelected(FString charname, FString player)
{
	for(auto& iter :SelectedButtons)
	{
		if (iter->OwnerID == player)
		{
			iter->SetVisibility(ESlateVisibility::Visible);
			iter->GetPlayerBorder()->SetVisibility(ESlateVisibility::Collapsed);
			iter->OwnerID = "";
			SelectedButtons.RemoveSingle(iter);
			break;
		}
	}

	for (auto& iter : SelecterArray)
	{
		if (iter->ButtonID == charname)
		{
			iter->SetVisibility(ESlateVisibility::HitTestInvisible);
			iter->SetSelectedPlayer(player);
			iter->GetPlayerBorder()->SetVisibility(ESlateVisibility::HitTestInvisible);
			SelectedButtons.Add(iter);
			break;
		}
	}
}

void UCharacterSelectScreen::ButtonReset()
{
	for (auto& iter : SelectedButtons)
	{
			iter->SetVisibility(ESlateVisibility::Visible);
			iter->GetPlayerBorder()->SetVisibility(ESlateVisibility::Collapsed);
			iter->OwnerID = "";
	}
	SelectedButtons.Empty();
}
