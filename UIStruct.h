#pragma once

#include "CoreMinimal.h"
#include "../Character/BaseCharacter/ProjectFBCharacter.h"
#include "UIStruct.generated.h"

UENUM(BlueprintType)
enum class ECostumeType : uint8
{
	Set UMETA(DisplayName = "Set"),
	Weapon UMETA(DisplayName = "Weapon"),
	Top UMETA(DisplayName = "Top"),
	Bottom UMETA(DisplayName = "Bottom"),
	Shoes UMETA(DisplayName = "Shoes"),
	Effect UMETA(DisplayName = "Effect"),
};

UENUM(BlueprintType)
enum EMatGrade : uint8
{
	Basic UMETA(DisplayName = "Basic"),
	Rare UMETA(DisplayName = "Rare"),
	Unique UMETA(DisplayName = "Unique"),
	Prime UMETA(DisplayName = "Prime"),
};

USTRUCT()
struct FCharacterProfile
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere)
		TObjectPtr<UTexture> texture;

	UPROPERTY(EditAnyWhere)
		FText name;

};

USTRUCT()
struct FCharacterInfo : public FCharacterProfile
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere)
		TSubclassOf<AProjectFBCharacter> CharacterBP;
};

USTRUCT()
struct FCostumeData : public FCharacterInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere)
		ECostumeType type = ECostumeType::Set;

	UPROPERTY(EditAnyWhere)
		bool IsUnlock = false;
};

USTRUCT()
struct FItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere)
		TObjectPtr<UTexture2D> texture = nullptr;

	UPROPERTY(EditAnyWhere)
		FText name;

	UPROPERTY(EditAnyWhere)
		int MaxStack = 0;

	UPROPERTY(EditAnyWhere)
		int Quanty = 0;

	UPROPERTY(EditAnyWhere)
		int Price = 0;
};

USTRUCT()
struct FCraftMatStuff
{
	GENERATED_BODY()

		UPROPERTY(EditAnyWhere)
		FText StuffName;

	UPROPERTY(EditAnyWhere)
		int32 RequaireQuanty = 0;
};

USTRUCT()
struct FCraftMaterial
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere)
		FText MatName;

	UPROPERTY(EditAnyWhere)
		int32 MatQuanty = 0;

	UPROPERTY(EditAnyWhere)
		int32 CraftPrice = 0;

	UPROPERTY(EditAnyWhere)
		TObjectPtr<UTexture2D> MatTexture;

	UPROPERTY(EditAnyWhere)
		TEnumAsByte<EMatGrade> MatGrade = Basic;

	UPROPERTY(EditAnyWhere)
		TArray<FCraftMatStuff> StuffArray;
};