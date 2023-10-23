// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySelector.h"

bool UAbilitySelector::Initialize()
{
	Super::Initialize();

	AbilityArray = BaseAbilityArray;

    m_AbilityButton1->GetAbilityButton()->OnPressed.AddDynamic(this, &UAbilitySelector::Button1);
    m_AbilityButton2->GetAbilityButton()->OnPressed.AddDynamic(this, &UAbilitySelector::Button2);
    m_AbilityButton3->GetAbilityButton()->OnPressed.AddDynamic(this, &UAbilitySelector::Button3);

    return true;
}

void UAbilitySelector::SetAbilityButton()
{
    RandomAbility = ShuffleAbility();
    m_AbilityButton1->SetAbilityStruct(RandomAbility[0]);
    m_AbilityButton2->SetAbilityStruct(RandomAbility[1]);
    m_AbilityButton3->SetAbilityStruct(RandomAbility[2]);
}

TArray<FAbilityStruct> UAbilitySelector::ShuffleAbility()
{
    TArray<FAbilityStruct> result;
    // Fisher-Yates shuffle
    for (int32 i = AbilityArray.Num() - 1; i > 0; i--)
    {
        int32 RandomIndex = FMath::RandRange(0, i);
        AbilityArray.Swap(i, RandomIndex);
    }

    for (int32 i = 0; i < 3; i++)
    {
        result.Add(AbilityArray[i]);
    }
    return result;
}

void UAbilitySelector::RemoveAbillityArrayElement(int buttonnum)
{
    AbilityArray.RemoveAt(buttonnum);
}

void UAbilitySelector::Button1()
{
    RemoveAbillityArrayElement(0);
}

void UAbilitySelector::Button2()
{
    RemoveAbillityArrayElement(1);
}

void UAbilitySelector::Button3()
{
    RemoveAbillityArrayElement(3);
}

ESelectorState UAbilitySelector::GetSelectorState()
{
    return state;
}

void UAbilitySelector::SetSelectorState(ESelectorState newstate)
{
    state = newstate;
}

UButton* UAbilitySelector::GetSelectorHandle()
{
    return SelectorHandle;
}