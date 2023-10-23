// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHPBar.h"

void UPlayerHPBar::SetNowHP(float hp)
{
	NowHPNUm = hp;
	NowHP->SetText(FText::AsNumber(NowHPNUm));
	float b = MaxHPNum;
	hp = FMath::Clamp<float>(hp, 0.0f, b);
	SetHPPercent(hp / b);
}

void UPlayerHPBar::SetMaxHP(float hp)
{
	MaxHPNum = hp;
	MaxHP->SetText(FText::AsNumber(MaxHPNum));
}

void UPlayerHPBar::SetHPPercent(float hpp)
{
	HPPercent->SetPercent(hpp);
}

void UPlayerHPBar::SetNowEP(float ep)
{
	NowEPNUm = ep;
	NowEP->SetText(FText::AsNumber(NowEPNUm));
	float b = MaxEPNum;
	ep = FMath::Clamp<float>(ep, 0.0f, b);
	SetEPPercent(ep / b);
}

void UPlayerHPBar::SetMaxEP(float ep)
{
	MaxEPNum = ep;
	MaxEP->SetText(FText::AsNumber(MaxEPNum));
}

void UPlayerHPBar::SetEPPercent(float epp)
{
	EPPercent->SetPercent(epp);
}