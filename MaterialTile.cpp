// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialTile.h"

void UMaterialTile::MatTileSet(FCraftMatStuff stuff, FCraftMaterial recipemat)
{
	m_stuff = stuff;
	m_recipemat = recipemat;
	UImage img;
	MatBorder->ClearChildren();
	img.Brush.SetResourceObject(recipemat.MatTexture);
	MatBorder->AddChild(&img);
	NeedQuanty->SetText(FText::AsNumber(stuff.RequaireQuanty));
	NowQuanty->SetText(FText::AsNumber(recipemat.MatQuanty));
	if (stuff.RequaireQuanty > recipemat.MatQuanty)
	{
		FSlateColor col(FLinearColor::Red);
		IsAble = false;
		NowQuanty->SetColorAndOpacity(col);
	}
}

bool UMaterialTile::GetIsAble(int quanty)
{
	if ((m_stuff.RequaireQuanty * quanty) <= m_recipemat.MatQuanty)
	{
		NeedQuanty->SetText(FText::AsNumber(m_stuff.RequaireQuanty * quanty));
		FSlateColor col(FLinearColor::White);
		IsAble = true;
		NowQuanty->SetColorAndOpacity(col);
	}
	else
	{
		NeedQuanty->SetText(FText::AsNumber(m_stuff.RequaireQuanty * quanty));
		FSlateColor col(FLinearColor::Red);
		IsAble = false;
		NowQuanty->SetColorAndOpacity(col);
	}
	return IsAble;
}
