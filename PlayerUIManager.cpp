// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerUIManager.h"

//UPlayerHPBar* UPlayerUIManager::GetPlayerHPBar()
//{
//	return m_PlayerHPBar;
//}
void UPlayerUIManager::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    m_AbilitySelector->GetSelectorHandle()->OnClicked.AddDynamic(this, &UPlayerUIManager::SelectorOnNOff);
}

UOccupationBar* UPlayerUIManager::GetOccupationBar()
{
	return m_OccupationBar;
}

UPlayerDie* UPlayerUIManager::GetPlayerDie()
{
	return m_PlayerDie;
}

UWidgetSwitcher* UPlayerUIManager::GetWidgetSwitcher()
{
	return m_WidgetSwitcher;
}

UPlayerPortrait* UPlayerUIManager::GetPlayerPortrait()
{
	return m_PlayerPortrait;
}

UAbilitySelector* UPlayerUIManager::GetAbilitySelector()
{
	return m_AbilitySelector;
}

UGameEnd* UPlayerUIManager::GetGameEnd()
{
    return m_GameEnd;
}

UTeamInfoPanel* UPlayerUIManager::GetTeamInfoPanel()
{
    return m_TeamInfoPanel;
}

void UPlayerUIManager::SelectorOnNOff()
{
    switch (m_AbilitySelector->GetSelectorState())
    {
    case Open:
        PlayAnimationReverse(SelectorMove);
        m_AbilitySelector->SetSelectorState(Close);
        break;
    case Close:
        PlayAnimationForward(SelectorMove);
        m_AbilitySelector->SetSelectorState(Open);
        break;
    default:
        break;
    }
}