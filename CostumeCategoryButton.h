// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "CostumeCategoryButton.generated.h"

/**
 * 
 */
UENUM()
enum EPanelnum
{
	Set,
	Weapon,
	Top,
	Bottom,
	Shoes,
	Effect,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClickedSignature, class UCostumeCategoryButton*, Button);

UCLASS()
class PROJECTFB_API UCostumeCategoryButton : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

	EPanelnum num;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> CategoryButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> ButtonName;

public:

	FOnClickedSignature OnClickedDelegate;

	UFUNCTION()
		UTextBlock* GetButtonName();

	UFUNCTION()
		void SetPanelNum(EPanelnum panelnum);

	UFUNCTION()
		EPanelnum GetPanelNum();

	UFUNCTION()
		void OnButtonClicked();
	
};
