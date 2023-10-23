// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CostumePanel.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "CostumePanel.h"
#include "CostumeCategoryButton.h"
#include "DressRoomScreen.generated.h"

/**
 * 
 */

UCLASS()
class PROJECTFB_API UDressRoomScreen : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumeCategoryButton> Set;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumeCategoryButton> Weapon;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumeCategoryButton> Top;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumeCategoryButton> Bottom;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumeCategoryButton> Shoes;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumeCategoryButton> Effect;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UWidgetSwitcher> DressRoomSwitcher;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumePanel> SetPanel;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumePanel> WeaponPanel;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumePanel> TopPanel;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumePanel> BottomPanel;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumePanel> ShoesPanel;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UCostumePanel> EffectPanel;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> CloseButton;
	
	UFUNCTION()
		void ChangeWidget(UCostumeCategoryButton* button);

	UFUNCTION()
		void CloseWidget();

};
