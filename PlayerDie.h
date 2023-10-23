// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "PlayerDie.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UPlayerDie : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> RespawnTimeRemain;

public:

	UFUNCTION()
	void SetRespawnTime(int time);
};
