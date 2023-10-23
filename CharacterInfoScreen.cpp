// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterInfoScreen.h"
#include "CharacterSelectButton.h"


void UCharacterInfoScreen::NativeOnInitialized()
{
	for (auto& iter : CharacterProfile)
	{
		UCharacterSelectButton* button = CreateWidget<UCharacterSelectButton>(CharacterWrapBox, buttonclass);

		button->ButtonInitialize(iter);
		CharacterWrapBox->AddChildToWrapBox(button);
	}
}