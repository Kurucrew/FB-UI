// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TeamInfo.h"
#include "Components/VerticalBox.h"
#include "TeamInfoPanel.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTFB_API UTeamInfoPanel : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UVerticalBox> m_VerticalBox;

	UPROPERTY(EditAnyWhere)
		TSubclassOf<class UTeamInfo> teaminfoclass;

	UPROPERTY()
		TArray<class AProjectFBCharacter*> TeamArr;

	UPROPERTY()
		TArray<UTeamInfo*> InfoArr;

public:

	UFUNCTION()
		void InitTeamInfo(TArray<class AProjectFBCharacter*> arr);

	UFUNCTION()
		void UpdateInfo(FString name);

	
};
