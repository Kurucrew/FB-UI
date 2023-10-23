// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "CharacterSelectButton.generated.h"

/**
 * 
 */

UCLASS()
class PROJECTFB_API UCharacterSelectButton : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> SelectButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> CharacterName;

public:

	UFUNCTION()
		void ButtonInitialize(FCharacterProfile profile);
};
