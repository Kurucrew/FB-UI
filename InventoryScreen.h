// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetSwitcher.h"
#include "Components/Button.h"
#include "InventoryScreen.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UInventoryScreen : public UUserWidget
{
	GENERATED_BODY()

		virtual void NativeOnInitialized() override;

		UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> CloseButton;

public:

	UFUNCTION()
		void CloseWidget();
	
};
