// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPortrait.h"

void UPlayerPortrait::SetPlayerLevel(int lv)
{
	PlayerLevel->SetText(FText::AsNumber(lv));
}

void UPlayerPortrait::SetPlayerExpBar(float exp, float maxexp)
{
	PlayerExpBar->SetPercent(exp / maxexp);
}