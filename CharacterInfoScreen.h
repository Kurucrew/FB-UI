// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/WrapBox.h"
#include "UIStruct.h"
#include "CharacterInfoScreen.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UCharacterInfoScreen : public UUserWidget
{
	GENERATED_BODY()
	
		virtual void NativeOnInitialized() override;

	UPROPERTY(EditAnyWhere)
		TArray<FCharacterProfile> CharacterProfile;

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UWrapBox> CharacterWrapBox;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UCharacterSelectButton> buttonclass;

};
