// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FBOccupationField.generated.h"

UENUM(BlueprintType)
enum class EOccupationState : uint8
{
	Null								UMETA(DisplayName = "Null"),
	OS_Deactivate						UMETA(DisplayName = "Deactivate"),
	OS_Activate							UMETA(DisplayName = "Activate"),
	OS_Combat							UMETA(DisplayName = "Combat"),
	OS_Occupying						UMETA(DisplayName = "Occupying"),
	OS_Occupied							UMETA(DisplayName = "Occupied"),
};

UCLASS()
class PROJECTFB_API AFBOccupationField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFBOccupationField();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Occupation Field Overlap Begin Event
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Occupation Field Overlap End Event
	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	// Set Occupation State Server
	UFUNCTION(Server, BlueprintCallable, Category="FB_OccupationField", Reliable )
	void SetOccupationState_Server(EOccupationState ocState);

	// Set Occupation State NetMulti
	UFUNCTION(NetMulticast, Category="FB_OccupationField", Reliable )
	void SetOccupationState_NetMulti(EOccupationState ocState);

	// Chceck Occupation State
	UFUNCTION()
	void CheckOccupationState();

	UFUNCTION(BlueprintPure, Category="FB_OccupationField")
	class AFBGameState* GetFBGameState();

	UFUNCTION()
	void UpdateOccupationTime();

	UFUNCTION()
	void CompleteOccupation();

	UFUNCTION()
	void SetOccupationBar(FString info, FColor color);

	UFUNCTION()
	void PlayerOutEvent();

	// Initialize Occupation Field;
	UFUNCTION()
	void InitField();

	UPROPERTY()
		TObjectPtr<class AFBPlayerController> PlayerController;

public:
	// Occupation Boundary Size 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=FB_OccupationField)
		TObjectPtr<class UBoxComponent> OccupationFieldBox;

	// Occupation State Particle
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=FB_OccupationField)
		TObjectPtr<class UParticleSystemComponent> ParticleComponent;

	// Current Occupation State
	UPROPERTY(Replicated,BlueprintReadWrite,EditAnywhere, Category=FB_OccupationField)
		EOccupationState OccupationState = EOccupationState::OS_Deactivate;

	// Inside Field Actor Array
	UPROPERTY(Replicated, BlueprintReadWrite,EditAnywhere, Category=FB_OccupationField)
	TArray<AActor*> InsideFieldActorArray;


	// Inside Field Team Member Nums 
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category=FB_OccupationField)
	TArray<int> CurrentInsideTeamMemberCount;
	
	UPROPERTY(Replicated, BlueprintReadWrite,EditAnywhere, Category=FB_OccupationField)
	TArray<float> TeamOccupationTime;

	UPROPERTY(Replicated, BlueprintReadWrite,EditAnywhere, Category=FB_OccupationField)
	int32 CurrentOccupationTeam = -1;
	
	UPROPERTY()
	class AFBGameState* FBGameMode = nullptr;

	UPROPERTY()
	FTimerHandle OccupationTimerHandle;

	UPROPERTY()
	FTimerHandle PlayerOutTimerHandle;

	
};
