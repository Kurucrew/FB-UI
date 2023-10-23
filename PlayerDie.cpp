// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDie.h"

void UPlayerDie::SetRespawnTime(int time)
{
	RespawnTimeRemain->SetText(FText::AsNumber(time));
}