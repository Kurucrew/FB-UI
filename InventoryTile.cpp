// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryTile.h"

void UInventoryTile::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UInventoryTile::SetTile()
{
	if (itemdata.Quanty <= 0)
	{
		ItemTexture->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		ItemTexture->SetVisibility(ESlateVisibility::Visible);
		ItemTexture->SetBrushFromTexture(itemdata.texture);
	}
}

void UInventoryTile::SetItemData(FItemData data)
{
	itemdata = data;
}

FItemData UInventoryTile::GetItemData()
{
	return itemdata;
}

void UInventoryTile::SetIndex(int i)
{
	Index = i;
}
