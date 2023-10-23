// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerProfile.h"

void UPlayerProfile::NativeOnInitialized()
{
	ProfileMenuButton->OnClicked.AddDynamic(this, &UPlayerProfile::PopUp);
}

void UPlayerProfile::PopUp()
{
	switch (State)
	{
	case MenuOpen:
		PlayAnimationReverse(MenuPopUp);
		State = MenuClose;
		break;
	case MenuClose:
		PlayAnimationForward(MenuPopUp);
		State = MenuOpen;
		break;
	default:
		break;
	}
}

UButton* UPlayerProfile::GetProfileButton()
{
	return ProfileButton;
}

UButton* UPlayerProfile::GetCostumeButton()
{
	return CostumeButton;
}

UButton* UPlayerProfile::GetInventoryButton()
{
	return InventoryButton;
}

void UPlayerProfile::NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent)
{
	Super::NativeOnRemovedFromFocusPath(InFocusEvent);

	if (State == MenuOpen)
	{
		PopUp();
	}
}