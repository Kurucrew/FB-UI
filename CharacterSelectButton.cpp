// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterSelectButton.h"
#include "CharacterInfoScreen.h"

void UCharacterSelectButton::ButtonInitialize(FCharacterProfile profile)
{
	SelectButton->WidgetStyle.Normal.SetResourceObject(profile.texture);
	SelectButton->WidgetStyle.Hovered.SetResourceObject(profile.texture);
	SelectButton->WidgetStyle.Pressed.SetResourceObject(profile.texture);
	CharacterName->SetText(profile.name);
}