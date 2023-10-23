// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "CostumeButton.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UCostumeButton : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> m_CostumeButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UBorder> Border;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> ButtonState;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> ItemName;

	UPROPERTY()
		TObjectPtr<class UCostumePanel> panelptr;
	
public:

	UFUNCTION()
		void ButtonInitialize(FCostumeData data, class UCostumePanel* panel);

	UFUNCTION()
		void Selected();

	UFUNCTION()
		void Unselect();

};
