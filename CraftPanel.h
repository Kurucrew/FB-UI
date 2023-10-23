// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/WrapBox.h"
#include "UIStruct.h"
#include "CraftPanel.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UCraftPanel : public UUserWidget
{
	GENERATED_BODY()

		virtual void NativeOnInitialized() override;

		UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> MaterialGrade;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UWrapBox> CraftWrapBox;

	UPROPERTY(EditAnyWhere)
		TSubclassOf<class UCraftTile> CraftTileClass;

	UPROPERTY()
		TArray<class UCraftTile*> CraftTiles;

	UPROPERTY(EditAnyWhere)
		TArray<FCraftMaterial> RecipeArray;

	UPROPERTY()
		TObjectPtr<class UCraftTile> PrevTile;

public:

	UFUNCTION()
		void RecipeSelected(class UCraftTile* tile);

	UFUNCTION()
		TArray<FCraftMaterial> GetRecipeArray();

	UFUNCTION()
		void SetRecipe();
	
};
