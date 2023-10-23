// Fill out your copyright notice in the Description page of Project Settings.


#include "CostumeCategoryButton.h"

void UCostumeCategoryButton::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	CategoryButton->OnClicked.AddDynamic(this, &UCostumeCategoryButton::OnButtonClicked);
}

UTextBlock* UCostumeCategoryButton::GetButtonName()
{
	return ButtonName;
}

void UCostumeCategoryButton::SetPanelNum(EPanelnum panelnum)
{
	num = panelnum;
}

EPanelnum UCostumeCategoryButton::GetPanelNum()
{
	return num;
}

void UCostumeCategoryButton::OnButtonClicked()
{
	OnClickedDelegate.Broadcast(this);
}
