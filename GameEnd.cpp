// Fill out your copyright notice in the Description page of Project Settings.


#include "GameEnd.h"
#include "Character/BaseCharacter/ProjectFBCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "../Game/FBGameInstance.h"
#include "../Server/Packets.h"

void UGameEnd::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ExitButton->OnClicked.AddDynamic(this, &UGameEnd::ExitGame);
}

void UGameEnd::SetGameResult(FString ret)
{
	GameResult->SetText(FText::FromString(ret));
}

void UGameEnd::ExitGame()
{
	AProjectFBCharacter* pc = Cast<AProjectFBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (pc)
	{
		UFBGameInstance* inst = Cast<UFBGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
		FSendPacket_GameEnd packet;
		packet.playerid = inst->PlayerId;
		inst->SendData(packet);

		const FName LevelName = TEXT("Lobby");
		UGameplayStatics::OpenLevel(GetWorld(), LevelName);
	}
}