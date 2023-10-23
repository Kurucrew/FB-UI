// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "AbilityButton.generated.h"

/**
 * 
 */
USTRUCT()
struct FAbilityStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere)
	FText AbilityName;

	UPROPERTY(EditAnyWhere)
	TObjectPtr<UTexture2D> AbilityImage;

	UPROPERTY(EditAnyWhere)
	FText AbilityInfo;

	UPROPERTY(EditAnyWhere)
	int AbilityKey = -1;
};

UCLASS()
class PROJECTFB_API UAbilityButton : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> m_AbilityButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> AbilityText;

	UPROPERTY()
		FAbilityStruct m_AbilityStruct;

	virtual bool Initialize() override;

	UFUNCTION()
		void SelectAbility();

	UFUNCTION()
		void SetAbilityTextuer();

	UFUNCTION()
		void SetAbilityText();

	UFUNCTION()
		void ActiveAbilityFunction();
	
public:

	UFUNCTION()
		void SetAbilityStruct(FAbilityStruct ability);

	UFUNCTION()
		UButton* GetAbilityButton();
};
