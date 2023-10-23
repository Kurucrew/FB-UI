// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/WrapBox.h"
#include "UIStruct.h"
#include "Components/TextBlock.h"
#include "CharacterSelectScreen.generated.h"

/**
 * 
 */
enum EReadyState
{
	Cancle,
	Ready,
};

UCLASS()
class PROJECTFB_API UCharacterSelectScreen : public UUserWidget
{
	GENERATED_BODY()
	
	virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnyWhere)
		TArray<FCharacterInfo> CharacterArray;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UWrapBox> CharacterWrapBox;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> TimeText;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> ReadyButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> ButtonText;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UInGameCharacterSelectButton> ButtonBP;

	UPROPERTY()
		TArray<class UInGameCharacterSelectButton*> SelectedButtons;

	UPROPERTY()
		bool IsReady = false;

		EReadyState ButtonState = Cancle;

	UPROPERTY()
		TArray<UInGameCharacterSelectButton*> SelecterArray;

public:

	UFUNCTION()
		void SetTimerWidget(int time);

	UFUNCTION()
		void ReadyToPlay();

	UFUNCTION()
		void CharacterSelected(class UInGameCharacterSelectButton* selected);

	UFUNCTION()
		void RecvCharacterSelected(FString charname, FString player);

	UFUNCTION()
		void ButtonReset();

	UPROPERTY()
		bool IsSelected = false;

};
