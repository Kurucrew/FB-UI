// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIStruct.h"
#include "Components/WidgetSwitcher.h"
#include "CraftPanel.h"
#include "MaterialTile.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"
#include "CraftScreen.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UCraftScreen : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> RareButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> UniqueButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> PrimeButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UWidgetSwitcher> CraftSwitcher;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCraftPanel> m_RarePanel;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCraftPanel> m_UniquePanel;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCraftPanel> m_PrimePanel;

	UPROPERTY()
		TArray<UCraftPanel*> Panels;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UMaterialTile> m_MaterialTile1;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UMaterialTile> m_MaterialTile2;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UMaterialTile> m_MaterialTile3;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UMaterialTile> m_MaterialTile4;

	UPROPERTY()
		TArray<UMaterialTile*> MatTiles;

	UPROPERTY(EditAnyWhere)
		TArray<FCraftMaterial> mats;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> CraftButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UEditableTextBox> QuantyInput;

	UFUNCTION()
		void OpenRarePanel();

	UFUNCTION()
		void OpenUniquePanel();

	UFUNCTION()
		void OpenPrimePanel();


public:

	UFUNCTION()
		void SetCraftMat(FCraftMaterial craftmat);

	UFUNCTION()
		void CheckQuanty(int quanty);

	UFUNCTION()
		void Crafting();

	UFUNCTION()
		void ChangeResultQuanty(const FText& num);
	
};
