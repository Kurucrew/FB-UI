// Fill out your copyright notice in the Description page of Project Settings.


#include "CostumeButton.h"
#include "CostumePanel.h"

void UCostumeButton::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	m_CostumeButton->OnClicked.AddDynamic(this, &UCostumeButton::Selected);
}

void UCostumeButton::ButtonInitialize(FCostumeData data, class UCostumePanel* panel)
{
	m_CostumeButton->WidgetStyle.Normal.SetResourceObject(data.texture);
	m_CostumeButton->WidgetStyle.Hovered.SetResourceObject(data.texture);
	m_CostumeButton->WidgetStyle.Pressed.SetResourceObject(data.texture);
	ItemName->SetText(data.name);

	panelptr = panel;

	if (data.IsUnlock == false)
	{
		this->SetColorAndOpacity({ 1,1,1,0.5f });
		this->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}

void UCostumeButton::Selected()
{
	if (IsValid(panelptr->GetPrevButton()))
	{
		panelptr->GetPrevButton()->Unselect();
	}
	Border->SetBrushColor({ 1,1,0,1 });
	ButtonState->SetText(FText::FromString("Selected"));
	ButtonState->SetVisibility(ESlateVisibility::HitTestInvisible);
	panelptr->SetPrevButton(this);
}

void UCostumeButton::Unselect()
{
	Border->SetBrushColor({1,1,1,1});
	ButtonState->SetVisibility(ESlateVisibility::Collapsed);
}
