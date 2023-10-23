// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/GridPanel.h"
#include "InventoryTile.h"
#include "InventoryPanel.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UInventoryPanel : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UGridPanel> InventoryGrid;

	UPROPERTY(EditAnyWhere)
		int InventorySize;
	
	UPROPERTY(EditAnyWhere)
		TSubclassOf<class UInventoryTile> tileclass;

public:

	UPROPERTY(EditAnyWhere)
		TArray<FItemData> ItemArray;

	UFUNCTION()
		void SetInventoryGrid();

};
