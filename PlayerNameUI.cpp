// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerNameUI.h"

void UPlayerNameUI::SetPlayerName(FText name)
{
	PlayerName->SetText(name);
}

void UPlayerNameUI::SetPlayerLevel(int level)
{
	PlayerLevel->SetText(FText::AsNumber(level));
}

void UPlayerNameUI::SetPlayerHPBar(float hp, float maxhp)
{
	PlayerHPBar->SetPercent(hp/maxhp);
}