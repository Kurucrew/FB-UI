// Fill out your copyright notice in the Description page of Project Settings.


#include "DressRoomScreen.h"
#include "Controller/ServerController/LobbyController.h"

void UDressRoomScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Set->GetButtonName()->SetText(FText::FromString("Set"));
	Set->SetPanelNum(EPanelnum::Set);
	Weapon->GetButtonName()->SetText(FText::FromString("Weapon"));
	Weapon->SetPanelNum(EPanelnum::Weapon);
	Top->GetButtonName()->SetText(FText::FromString("Top"));
	Top->SetPanelNum(EPanelnum::Top);
	Bottom->GetButtonName()->SetText(FText::FromString("Bottom"));
	Bottom->SetPanelNum(EPanelnum::Bottom);
	Shoes->GetButtonName()->SetText(FText::FromString("Shoes"));
	Shoes->SetPanelNum(EPanelnum::Shoes);
	Effect->GetButtonName()->SetText(FText::FromString("Effect"));
	Effect->SetPanelNum(EPanelnum::Effect);

	Set->OnClickedDelegate.AddDynamic(this, &UDressRoomScreen::ChangeWidget);
	Weapon->OnClickedDelegate.AddDynamic(this, &UDressRoomScreen::ChangeWidget);
	Top->OnClickedDelegate.AddDynamic(this, &UDressRoomScreen::ChangeWidget);
	Bottom->OnClickedDelegate.AddDynamic(this, &UDressRoomScreen::ChangeWidget);
	Shoes->OnClickedDelegate.AddDynamic(this, &UDressRoomScreen::ChangeWidget);
	Effect->OnClickedDelegate.AddDynamic(this, &UDressRoomScreen::ChangeWidget);

	CloseButton->OnClicked.AddDynamic(this, &UDressRoomScreen::CloseWidget);
}

void UDressRoomScreen::ChangeWidget(UCostumeCategoryButton* button)
{
	DressRoomSwitcher->SetActiveWidgetIndex(button->GetPanelNum());
}

void UDressRoomScreen::CloseWidget()
{
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	GetWorld()->GetFirstPlayerController<ALobbyController>()->GoToMainScreen();
}
