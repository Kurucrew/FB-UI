// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "UIStruct.h"
#include "CraftTile.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMatButtonClicked, class UCraftTile*, matbutton);

UCLASS()
class PROJECTFB_API UCraftTile : public UUserWidget
{
	GENERATED_BODY()

		virtual void NativeOnInitialized() override;

		UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButton> MaterialButton;
	
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> MaterialName;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> MaterialQuanty;

	UPROPERTY()
		TObjectPtr<UTexture2D> MaterialTexture;

	UPROPERTY()
		FCraftMaterial MatData;

public:

	FMatButtonClicked MatClickedDel;

	UFUNCTION()
		void CraftMatSelected();

	UFUNCTION()
		void InitMatButton(FCraftMaterial mat);

	UFUNCTION()
		void SetMatQuanty(int32 qunaty);

	UFUNCTION()
		FText GetMaterialName();

	UFUNCTION()
		struct FCraftMaterial GetMatData();
};
