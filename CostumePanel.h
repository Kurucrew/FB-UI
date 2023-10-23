// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIStruct.h"
#include "Components/WrapBox.h"
#include "CostumePanel.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UCostumePanel : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnyWhere)
		TArray<FCostumeData> CostumeData;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UWrapBox> CostumeWrapBox;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UCostumeButton> buttonclass;

	UPROPERTY()
		TObjectPtr<UCostumeButton> PrevButton;

public:

	UFUNCTION()
		UCostumeButton* GetPrevButton();

	UFUNCTION()
		void SetPrevButton(UCostumeButton* button);
	
};
