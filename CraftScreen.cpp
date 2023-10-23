// Fill out your copyright notice in the Description page of Project Settings.


#include "CraftScreen.h"

void UCraftScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	for (auto& iter : mats)
	{
		switch (iter.MatGrade)
		{
		case EMatGrade::Rare:
			m_RarePanel->GetRecipeArray().Add(iter);
			break;

		case EMatGrade::Unique:
			m_UniquePanel->GetRecipeArray().Add(iter);
			break;

		case EMatGrade::Prime:
			m_PrimePanel->GetRecipeArray().Add(iter);
			break;

		default:
			break;
		}
	}
	m_RarePanel->SetRecipe();
	m_UniquePanel->SetRecipe();
	m_PrimePanel->SetRecipe();

	Panels.Add(m_RarePanel);
	Panels.Add(m_UniquePanel);
	Panels.Add(m_PrimePanel);
	MatTiles.Add(m_MaterialTile1);
	MatTiles.Add(m_MaterialTile2);
	MatTiles.Add(m_MaterialTile3);
	MatTiles.Add(m_MaterialTile4);

	RareButton->OnClicked.AddDynamic(this, &UCraftScreen::OpenRarePanel);
	UniqueButton->OnClicked.AddDynamic(this, &UCraftScreen::OpenUniquePanel);
	PrimeButton->OnClicked.AddDynamic(this, &UCraftScreen::OpenPrimePanel);
	CraftButton->OnClicked.AddDynamic(this, &UCraftScreen::Crafting);
	QuantyInput->OnTextChanged.AddDynamic(this, &UCraftScreen::ChangeResultQuanty);
}

void UCraftScreen::OpenRarePanel()
{
	CraftSwitcher->SetActiveWidgetIndex(0);
}

void UCraftScreen::OpenUniquePanel()
{
	CraftSwitcher->SetActiveWidgetIndex(1);
}

void UCraftScreen::OpenPrimePanel()
{
	CraftSwitcher->SetActiveWidgetIndex(2);
}

void UCraftScreen::SetCraftMat(FCraftMaterial craftmat)
{
	FCraftMaterial recipe;
	for (int i =0; i < craftmat.StuffArray.Num(); i++)
	{
		for (auto& iter : mats)
		{
			if (iter.MatName.EqualTo(craftmat.StuffArray[i].StuffName))
			{
				recipe = iter;
				break;
			}
		}
		MatTiles[i]->MatTileSet(craftmat.StuffArray[i], recipe);
	}
	CheckQuanty(1);
}

void UCraftScreen::CheckQuanty(int quanty)
{
	if (m_MaterialTile1->GetIsAble(quanty) &&
		m_MaterialTile2->GetIsAble(quanty) &&
		m_MaterialTile3->GetIsAble(quanty) &&
		m_MaterialTile4->GetIsAble(quanty))
	{
		CraftButton->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		CraftButton->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}

void UCraftScreen::Crafting()
{
}

void UCraftScreen::ChangeResultQuanty(const FText& num)
{
	if (num.IsNumeric() && FCString::Atoi(*num.ToString()) > 0)
	{
		CheckQuanty(FCString::Atoi(*num.ToString()));
	}
	else
	{
		QuantyInput->SetText(FText::AsNumber(1));
		CheckQuanty(1);
	}
}
