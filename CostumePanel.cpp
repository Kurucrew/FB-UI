// Fill out your copyright notice in the Description page of Project Settings.


#include "CostumePanel.h"
#include "CostumeButton.h"

void UCostumePanel::NativeOnInitialized()
{
	for (auto& iter : CostumeData)
	{
		UCostumeButton* button = CreateWidget<UCostumeButton>(CostumeWrapBox, buttonclass);

		button->ButtonInitialize(iter, this);
		CostumeWrapBox->AddChildToWrapBox(button);
	}
}

UCostumeButton* UCostumePanel::GetPrevButton()
{
	return PrevButton;
}

void UCostumePanel::SetPrevButton(UCostumeButton* button)
{
	PrevButton = button;
}
