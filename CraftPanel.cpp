// Fill out your copyright notice in the Description page of Project Settings.


#include "CraftPanel.h"
#include "CraftTile.h"
#include "Controller/ServerController/LobbyController.h"

void UCraftPanel::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UCraftPanel::RecipeSelected(UCraftTile* tile)
{
	if (IsValid(PrevTile))
	{
		PrevTile->SetVisibility(ESlateVisibility::Visible);
	}

	PrevTile = tile;
	tile->SetVisibility(ESlateVisibility::HitTestInvisible);
	GetWorld()->GetFirstPlayerController<ALobbyController>()->GetLobbyUI()->GetCraftScreen()->SetCraftMat(tile->GetMatData());//제작창 함수 만들어야함;
}

TArray<FCraftMaterial> UCraftPanel::GetRecipeArray()
{
	return RecipeArray;
}

void UCraftPanel::SetRecipe()
{
	for (auto& iter : RecipeArray)
	{
		UCraftTile* tile = CreateWidget<UCraftTile>(CraftWrapBox, CraftTileClass);
		tile->InitMatButton(iter);
		tile->MatClickedDel.AddDynamic(this, &UCraftPanel::RecipeSelected);
		CraftWrapBox->AddChildToWrapBox(tile);
	}
}
