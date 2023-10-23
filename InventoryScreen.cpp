// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryScreen.h"
#include "Controller/ServerController/LobbyController.h"

void UInventoryScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CloseButton->OnClicked.AddDynamic(this, &UInventoryScreen::CloseWidget);
}

void UInventoryScreen::CloseWidget()
{
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	GetWorld()->GetFirstPlayerController<ALobbyController>()->GoToMainScreen();
}
