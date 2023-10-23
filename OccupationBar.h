// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "OccupationBar.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UOccupationBar : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> OccupationMassage;

	int OccupationProgress = 0;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> OccupationProgressBar;

public:

	UFUNCTION()
		void SetOccupationMassage(FString massage);

	UFUNCTION()
		void SetOccupationColor(FColor color);

	UFUNCTION()
		void SetOccupationProgress(float progress);
	
};
