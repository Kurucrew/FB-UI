// Fill out your copyright notice in the Description page of Project Settings.


#include "TeamInfoPanel.h"
#include "Character/BaseCharacter/ProjectFBCharacter.h"

void UTeamInfoPanel::InitTeamInfo(TArray<class AProjectFBCharacter*> arr)
{
	for (int i = 0; i < arr.Num(); i++)
	{
		if (arr[i] != GetWorld()->GetFirstPlayerController()->GetPawn())
		{
			UTeamInfo* teaminfo = CreateWidget<UTeamInfo>(this, teaminfoclass);

			InfoArr.Add(teaminfo);
			TeamArr.Add(arr[i]);

			teaminfo->SetNickname(arr[i]->GetNickname());
			teaminfo->SetLvl(arr[i]->GetCharacterLevel());
			teaminfo->SetHPBar(arr[i]->GetHealth() / arr[i]->GetMaxHealth());

			m_VerticalBox->AddChild(teaminfo);
		}
	}
}

void UTeamInfoPanel::UpdateInfo(FString name)
{
	for (int i = 0; i < TeamArr.Num(); i++)
	{
		if (TeamArr[i]->GetNickname() == name)
		{
			InfoArr[i]->SetLvl(TeamArr[i]->GetCharacterLevel());
			InfoArr[i]->SetHPBar(TeamArr[i]->GetHealth() / TeamArr[i]->GetMaxHealth());
		}
	}
}
