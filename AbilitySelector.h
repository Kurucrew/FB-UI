// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AbilityButton.h"
#include "Components/Button.h"
#include "AbilitySelector.generated.h"

/**
 * 
 */
UENUM()
enum ESelectorState
{
	Open,
	Close,
};

UCLASS()
class PROJECTFB_API UAbilitySelector : public UUserWidget
{
	GENERATED_BODY()

		virtual bool Initialize() override;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> SelectorHandle;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UAbilityButton> m_AbilityButton1;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UAbilityButton> m_AbilityButton2;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UAbilityButton> m_AbilityButton3;

	UPROPERTY(EditAnyWhere)
		TArray<FAbilityStruct> BaseAbilityArray;

	UPROPERTY()
		TArray<FAbilityStruct> AbilityArray;

	UPROPERTY()
		TArray<FAbilityStruct> RandomAbility;

	UPROPERTY()
		TEnumAsByte<ESelectorState> state = Close;

	UFUNCTION()
		TArray<FAbilityStruct> ShuffleAbility();

	UFUNCTION()
		void RemoveAbillityArrayElement(int buttonnum);
	
	UFUNCTION()
		void Button1();

	UFUNCTION()
		void Button2();

	UFUNCTION()
		void Button3();

public:

	UFUNCTION(BlueprintCallable)
		void SetAbilityButton();

	UFUNCTION()
		ESelectorState GetSelectorState();

	UFUNCTION()
		UButton* GetSelectorHandle();

	UFUNCTION()
		void SetSelectorState(ESelectorState newstate);
};
