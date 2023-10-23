// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "PlayerProfile.generated.h"

/**
 * 
 */
enum ProfileState
{
	MenuOpen,
	MenuClose,
};

UCLASS()
class PROJECTFB_API UPlayerProfile : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

	virtual void NativeOnRemovedFromFocusPath(const FFocusEvent& InFocusEvent) override;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> UserName;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> ProfileMenuButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> ProfileButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> CostumeButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> InventoryButton;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
		TObjectPtr<UWidgetAnimation> MenuPopUp;

	ProfileState State = MenuClose;

public:

	UFUNCTION()
		void PopUp();

	UFUNCTION()
		UButton* GetProfileButton();

	UFUNCTION()
		UButton* GetCostumeButton();

	UFUNCTION()
		UButton* GetInventoryButton();

};
