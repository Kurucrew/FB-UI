// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchingAsk.h"
#include "../Controller/ServerController/LobbyController.h"

void UMatchingAsk::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	

	YButton->OnClicked.AddDynamic(this, &UMatchingAsk::MatchingAccept);
	NButton->OnClicked.AddDynamic(this, &UMatchingAsk::MatchingCancle);
}

void UMatchingAsk::MatchingAccept()
{
	GetWorld()->GetFirstPlayerController<ALobbyController>()->SendReadyMatching();
	MatchingSwitcher->SetActiveWidgetIndex(Accept);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
	GetWorld()->GetGameViewport()->SetMouseCaptureMode(EMouseCaptureMode::CapturePermanently);
}

void UMatchingAsk::MatchingCancle()
{
	GetWorld()->GetFirstPlayerController<ALobbyController>()->SendMatchingCancle();
	this->SetVisibility(ESlateVisibility::Collapsed);
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
	GetWorld()->GetGameViewport()->SetMouseCaptureMode(EMouseCaptureMode::CapturePermanently);
}

void UMatchingAsk::PlayerCount(int32 n, int32 m)
{
	Readyusers->SetText(FText::AsNumber(n));
	Maxusers->SetText(FText::AsNumber(m));
}

void UMatchingAsk::SwitcherDefault()
{
	MatchingSwitcher->SetActiveWidgetIndex(Idle);
}
