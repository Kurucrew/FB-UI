// Fill out your copyright notice in the Description page of Project Settings.


#include "CraftTile.h"

void UCraftTile::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	MaterialButton->OnClicked.AddDynamic(this, &UCraftTile::CraftMatSelected);
}

void UCraftTile::CraftMatSelected()
{
	this->SetColorAndOpacity({ 0, 0, 0, 0.5f });
	this->SetVisibility(ESlateVisibility::HitTestInvisible);
	MatClickedDel.Broadcast(this);
}

void UCraftTile::InitMatButton(FCraftMaterial mat)
{
	MaterialName->SetText(mat.MatName);
	MaterialQuanty->SetText(FText::AsNumber(mat.MatQuanty));
	MaterialTexture = mat.MatTexture;
	MaterialButton->WidgetStyle.Normal.SetResourceObject(MaterialTexture);
	MaterialButton->WidgetStyle.Hovered.SetResourceObject(MaterialTexture);
	MaterialButton->WidgetStyle.Pressed.SetResourceObject(MaterialTexture);
	MatData = mat;
}

void UCraftTile::SetMatQuanty(int32 qunaty)
{
	MaterialQuanty->SetText(FText::AsNumber(qunaty));
}

FText UCraftTile::GetMaterialName()
{
	return MaterialName->GetText();
}

FCraftMaterial UCraftTile::GetMatData()
{
	return MatData;
}
