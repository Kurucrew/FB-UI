// Fill out your copyright notice in the Description page of Project Settings.


#include "OccupationBar.h"

void UOccupationBar::SetOccupationMassage(FString massage)
{
	OccupationMassage->SetText(FText::FromString(massage));
}

void UOccupationBar::SetOccupationColor(FColor color)
{
	OccupationProgressBar->SetFillColorAndOpacity(color);
}

void UOccupationBar::SetOccupationProgress(float progress)
{
	OccupationProgressBar->SetPercent(progress);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Occupation :" + FString::SanitizeFloat(progress)));
}