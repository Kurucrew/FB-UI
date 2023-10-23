// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widget/CharacterSelectButton.h"
#include "../Character/BaseCharacter/ProjectFBCharacter.h"
#include "Components/Border.h"
#include "InGameCharacterSelectButton.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterSelectClicked, class UInGameCharacterSelectButton*, Button);

UCLASS()
class PROJECTFB_API UInGameCharacterSelectButton : public UCharacterSelectButton
{
	GENERATED_BODY()

		virtual void NativeOnInitialized() override;

	UPROPERTY()
		TSubclassOf<AProjectFBCharacter> CharacterBP;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> SelectedPlayer;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UBorder> PlayerBorder;

public:

	FCharacterSelectClicked SelectClickedDelegate;

	UPROPERTY()
		FString ButtonID;

	UPROPERTY()
		FString OwnerID;

	UFUNCTION()
		void InitSelectButton(FCharacterInfo profile);

	UFUNCTION()
		void CharacterSelect();

	UFUNCTION()
		void SetSelectedPlayer(FString name);

	UFUNCTION()
		UBorder* GetPlayerBorder();
};
