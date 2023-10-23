// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchingButton.h"
#include "Kismet/KismetStringLibrary.h"
#include "Controller/ServerController/LobbyController.h"

void UMatchingButton::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	MatchButton->OnClicked.AddDynamic(this, &UMatchingButton::Matching);
	GetOwningPlayer()->InputComponent->BindAction("Interaction", EInputEvent::IE_Pressed, this, &UMatchingButton::Matching);
}

void UMatchingButton::Matching()
{
	switch (State)
	{
	case End:
		m_Switcher->SetActiveWidgetIndex(Start);
		TimerStart = FDateTime::Now();
		GetWorld()->GetFirstPlayerController<ALobbyController>()->SendReadyRequest();
		GetWorld()->GetTimerManager().SetTimer(Timer, this, &UMatchingButton::StartTimer, 1.0f, true, 0.0f);
		State = Start;
		break;
	case Start:
		m_Switcher->SetActiveWidgetIndex(End);
		GetWorld()->GetFirstPlayerController<ALobbyController>()->SendReadyCancle();
		GetWorld()->GetTimerManager().ClearTimer(Timer);
		State = End;
		break;
	default:
		break;
	}
}

void UMatchingButton::StartTimer()
{
	FDateTime TimeNow = FDateTime::Now();

	float ElapsedSeconds = FTimespan(TimeNow - TimerStart).GetTotalSeconds();
	FString TimeString = UKismetStringLibrary::TimeSecondsToString(ElapsedSeconds);

	FText RetTime;
	if (TimeString.Len() > 5)
	{
		RetTime = FText::FromString(TimeString.Left(5));
	}
	else
	{
		RetTime = FText::FromString(TimeString);
	}

	MatchingTime->SetText(RetTime);
}

void UMatchingButton::MatchingCancle()
{
	m_Switcher->SetActiveWidgetIndex(End);
	GetWorld()->GetTimerManager().ClearTimer(Timer);
	State = End;
}
