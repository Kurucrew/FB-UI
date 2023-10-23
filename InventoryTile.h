// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "UIStruct.h"
#include "InventoryTile.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UInventoryTile : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

	UPROPERTY()
		FItemData itemdata;

	UPROPERTY()
		int Index;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UImage> ItemTexture;

public:

	UFUNCTION()
		void SetTile();

	UFUNCTION()
		void SetItemData(FItemData data);

	UFUNCTION()
		FItemData GetItemData();

	UFUNCTION()
		void SetIndex(int i);

};
