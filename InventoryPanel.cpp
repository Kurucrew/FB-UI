// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryPanel.h"

void UInventoryPanel::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	for (int i = 0; i < InventorySize; i++)
	{
		ItemArray.AddDefaulted();
	}

	SetInventoryGrid();
}

void UInventoryPanel::SetInventoryGrid()
{
	InventoryGrid->ClearChildren();

	for (int i = 0; i < ItemArray.Num(); i++)
	{
		UInventoryTile* tile = CreateWidget<UInventoryTile>(InventoryGrid, tileclass);
		tile->SetIndex(i);
		tile->SetItemData(ItemArray[i]);
		
		InventoryGrid->AddChildToGrid(tile, i / 8, i % 8);
	}
}
