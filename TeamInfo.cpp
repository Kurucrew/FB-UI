// Fill out your copyright notice in the Description page of Project Settings.


#include "TeamInfo.h"

void UTeamInfo::SetNickname(FString name)
{
	Nickname->SetText(FText::FromString(name));
}

void UTeamInfo::SetLvl(int lv)
{
	Lvl->SetText(FText::AsNumber(lv));
}

void UTeamInfo::SetHPBar(float hpp)
{
	HPBar->SetPercent(hpp);
}
