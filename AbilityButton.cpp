// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityButton.h"

bool UAbilityButton::Initialize()
{
	Super::Initialize();

	m_AbilityButton->OnPressed.AddDynamic(this, &UAbilityButton::SelectAbility);

	return true;
}

void UAbilityButton::SelectAbility()
{
	ActiveAbilityFunction();
}

void UAbilityButton::SetAbilityStruct(FAbilityStruct ability)
{
	m_AbilityStruct = ability;

	SetAbilityTextuer();
	SetAbilityText();
}

void UAbilityButton::SetAbilityTextuer()
{
	m_AbilityButton->WidgetStyle.Normal.SetResourceObject(m_AbilityStruct.AbilityImage);
	m_AbilityButton->WidgetStyle.Hovered.SetResourceObject(m_AbilityStruct.AbilityImage);
	m_AbilityButton->WidgetStyle.Pressed.SetResourceObject(m_AbilityStruct.AbilityImage);
}

void UAbilityButton::SetAbilityText()
{
	AbilityText->SetText(m_AbilityStruct.AbilityInfo);
}

void UAbilityButton::ActiveAbilityFunction()
{

}

UButton* UAbilityButton::GetAbilityButton()
{
	return m_AbilityButton;
}