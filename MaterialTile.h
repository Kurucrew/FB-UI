// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIStruct.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "MaterialTile.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UMaterialTile : public UUserWidget
{
	GENERATED_BODY()

		UPROPERTY(meta = (BindWidget))
		TObjectPtr<UBorder> MatBorder;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> NowQuanty;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> NeedQuanty;

	UPROPERTY()
		FCraftMatStuff m_stuff;

	UPROPERTY()
		FCraftMaterial m_recipemat;

	UPROPERTY()
		bool IsAble = true;

public:

	UFUNCTION()
		void MatTileSet(FCraftMatStuff stuff, FCraftMaterial recipemat);

	UFUNCTION()
		bool GetIsAble(int quanty);
	
};
