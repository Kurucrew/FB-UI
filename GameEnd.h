// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "GameEnd.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UGameEnd : public UUserWidget
{
	GENERATED_BODY()

		virtual void NativeOnInitialized() override;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> ExitButton;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> GameResult;

public:

	UFUNCTION()
		void SetGameResult(FString ret);

	UFUNCTION()
		void ExitGame();

};
