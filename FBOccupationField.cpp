// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/FBOccupationField.h"

#include "Character/FBBaseCharacter.h"
#include "Character/BaseCharacter/AICharacter.h"
#include "Character/BaseCharacter/ProjectFBCharacter.h"
#include "Components/BoxComponent.h"
#include "Game/FBGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "Particles/ParticleSystemComponent.h"

#define OCCUPATION_TIME 20.f

// Sets default values
AFBOccupationField::AFBOccupationField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 0.25f;

	SetReplicates(true);
	
	OccupationFieldBox = CreateDefaultSubobject<UBoxComponent>(TEXT("OccupationFiledSphereComp"));
	ParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));

	RootComponent = OccupationFieldBox ;
	ParticleComponent->SetupAttachment(RootComponent);
	
	
	OccupationFieldBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &AFBOccupationField::OnOverlapBegin);
	OccupationFieldBox->OnComponentEndOverlap.AddUniqueDynamic(this, &AFBOccupationField::OnOverlapEnd);
}

// Called when the game starts or when spawned
void AFBOccupationField::BeginPlay()
{
	Super::BeginPlay();

	// Add GameState->OccupationFields Array 
	AFBGameState* gameState = Cast<AFBGameState>(UGameplayStatics::GetGameState(this));
	if(IsValid(gameState))
	{
		gameState->OccupationFields.AddUnique(this);
	}
}

// Called every frame
void AFBOccupationField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(OccupationState != EOccupationState::OS_Deactivate &&
		OccupationState != EOccupationState::OS_Occupied &&
		OccupationState != EOccupationState::Null)
	{
		CheckOccupationState();
	}
}

void AFBOccupationField::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFBOccupationField, OccupationState);
	DOREPLIFETIME(AFBOccupationField, InsideFieldActorArray);
	DOREPLIFETIME(AFBOccupationField, CurrentOccupationTeam);
	DOREPLIFETIME(AFBOccupationField, TeamOccupationTime);
}


void AFBOccupationField::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if( OccupationState != EOccupationState::Null &&
		OccupationState != EOccupationState::OS_Occupied &&
		OccupationState != EOccupationState::OS_Deactivate && 
		Cast<AFBBaseCharacter>(OtherActor))
	{
		if (Cast<AFBBaseCharacter>(OtherActor)->GetController() == GetWorld()->GetFirstPlayerController())
		{
			PlayerController = Cast<AFBBaseCharacter>(OtherActor)->GetController<AFBPlayerController>();
			PlayerController->GetPlayerUI()->GetOccupationBar()->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		}
		InsideFieldActorArray.AddUnique(OtherActor);
		CheckOccupationState();
	}
}

void AFBOccupationField::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if( OccupationState != EOccupationState::Null &&
		OccupationState != EOccupationState::OS_Occupied &&
		OccupationState != EOccupationState::OS_Deactivate &&
		Cast<AFBBaseCharacter>(OtherActor))
	{
		if (Cast<AFBBaseCharacter>(OtherActor)->GetController() == GetWorld()->GetFirstPlayerController())
		{
			PlayerController->GetPlayerUI()->GetOccupationBar()->SetVisibility(ESlateVisibility::Collapsed);
			PlayerController = nullptr;
		}
		InsideFieldActorArray.Remove(OtherActor);
		CheckOccupationState();
	}
}

void AFBOccupationField::CheckOccupationState()
{
	bool bSatisfyCondition = false;

	for(auto& teamNum : CurrentInsideTeamMemberCount)
	{
		teamNum = 0;
	}
	CurrentOccupationTeam = -1;
	
	
	// Condition Check
	for(const auto& insideActor : InsideFieldActorArray)
	{
		if(Cast<AAICharacter>(insideActor))
		{
			SetOccupationState_Server(EOccupationState::OS_Combat);
		}
		
		else if(const AFBBaseCharacter* baseCharacter = Cast<AFBBaseCharacter>(insideActor))
		{
			if(CurrentInsideTeamMemberCount.IsValidIndex(baseCharacter->GetTeamID()) &&
				baseCharacter->GetHealth() > 0.0f)
			{
				CurrentInsideTeamMemberCount[baseCharacter->GetTeamID()]++;
			}
		}
	}

	// Team Member Number Check
	int InsideTeamNum = 0;
	for(int i = 0; i < CurrentInsideTeamMemberCount.Num(); ++i)
	{
		if(CurrentInsideTeamMemberCount[i] != 0)
		{
			InsideTeamNum++;
			CurrentOccupationTeam = i;
			SetOccupationState_Server(EOccupationState::OS_Activate);
		}

		if(CurrentInsideTeamMemberCount[i] == 0)
		{
			TeamOccupationTime[i] = 0.0f;
		}
		
		if(InsideTeamNum > 1)
		{
			CurrentOccupationTeam = -1;
			SetOccupationState_Server(EOccupationState::OS_Combat);
		}
	}

	if(CurrentOccupationTeam != -1)
	{
		const int maxTeamNumber = GetFBGameState()->GetPlayerTeams()[CurrentOccupationTeam].players.Num();
		
		if(CurrentInsideTeamMemberCount.IsValidIndex(CurrentOccupationTeam) &&
			maxTeamNumber <= CurrentInsideTeamMemberCount[CurrentOccupationTeam])
		{
			bSatisfyCondition = true;
			SetOccupationState_Server(EOccupationState::OS_Occupying);
		}
	}

	if(OccupationState == EOccupationState::OS_Occupying &&
	   InsideFieldActorArray.Num() == 0)
	{
		SetOccupationState_Server(EOccupationState::OS_Activate);
	}
	
	// When the above conditions are satisfied, the occupation timer starts.
	if(bSatisfyCondition)
	{
		if(GetWorldTimerManager().IsTimerActive(OccupationTimerHandle) == false)
			GetWorldTimerManager().SetTimer(OccupationTimerHandle, this, &AFBOccupationField::UpdateOccupationTime, 0.5f, true);
	}
	else
	{
		if(GetWorldTimerManager().IsTimerActive(OccupationTimerHandle))
			GetWorldTimerManager().ClearTimer(OccupationTimerHandle);
	}
}

AFBGameState* AFBOccupationField::GetFBGameState()
{
	if(FBGameMode)
		return FBGameMode;

	return FBGameMode = Cast<AFBGameState>(UGameplayStatics::GetGameState(GetWorld()));
}

void AFBOccupationField::UpdateOccupationTime()
{
	if(TeamOccupationTime.IsValidIndex(CurrentOccupationTeam))
	{
		TeamOccupationTime[CurrentOccupationTeam] += 0.5f;
		if(TeamOccupationTime[CurrentOccupationTeam] >= OCCUPATION_TIME)
		{
			CompleteOccupation();
		}
	}
}

void AFBOccupationField::CompleteOccupation()
{
	//TODO Occupation Complete
	SetOccupationState_Server(EOccupationState::OS_Occupied);
	
	// Activate Other Field
	GetFBGameState()->ActivateOccupationField();

	// Clear Timer
	GetWorldTimerManager().ClearTimer(OccupationTimerHandle);

	GetWorldTimerManager().SetTimer(PlayerOutTimerHandle, this, &AFBOccupationField::PlayerOutEvent, 1.0f, false);
}

void AFBOccupationField::InitField()
{
	CurrentOccupationTeam = -1;

	SetOccupationState_Server(EOccupationState::OS_Deactivate);
	
	CurrentInsideTeamMemberCount.Empty();
	TeamOccupationTime.Empty();
	
	for(auto teamP : 	Cast<AFBGameState>(UGameplayStatics::GetGameState(this))->GetPlayerTeams())
	{
		CurrentInsideTeamMemberCount.Add(0);
		TeamOccupationTime.Add(0);
	}

}


void AFBOccupationField::SetOccupationState_Server_Implementation(EOccupationState ocState)
{
	SetOccupationState_NetMulti(ocState);
}

void AFBOccupationField::SetOccupationState_NetMulti_Implementation(EOccupationState ocState)
{
	OccupationState = ocState;

	if (IsValid(PlayerController))
	{
		switch (OccupationState)
		{
		case EOccupationState::OS_Activate:
			SetOccupationBar("Wait Occupying", FColor::Yellow);
			break;
		case EOccupationState::OS_Combat:
			SetOccupationBar("Combat", FColor::Red);
			break;
		case EOccupationState::OS_Occupying:
			SetOccupationBar("Occupying", FColor::Blue);
			break;
		default:
			break;
		}
	}
}

void AFBOccupationField::SetOccupationBar(FString info, FColor color)
{
	PlayerController->GetPlayerUI()->GetOccupationBar()->SetOccupationMassage(info);
	PlayerController->GetPlayerUI()->GetOccupationBar()->SetOccupationColor(color);
	if(TeamOccupationTime.IsValidIndex(PlayerController->GetPawn<AProjectFBCharacter>()->GetTeamID()))
	{
		PlayerController->GetPlayerUI()->GetOccupationBar()->SetOccupationProgress(TeamOccupationTime[PlayerController->GetPawn<AProjectFBCharacter>()->GetTeamID()] / OCCUPATION_TIME);
	}
}

void AFBOccupationField::PlayerOutEvent()
{
	AProjectFBCharacter* pc = Cast<AProjectFBCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if(pc)
	{
		if (pc->GetTeamID() == CurrentOccupationTeam)
		{
			pc->GetController<AFBPlayerController>()->GetPlayerUI()->GetGameEnd()->SetGameResult("Win");
			pc->GetController<AFBPlayerController>()->GetPlayerUI()->GetWidgetSwitcher()->SetActiveWidgetIndex(WigetIndex::GameEnd);
			pc->GetController<AFBPlayerController>()->SetShowMouseCursor(true);
			pc->GetController<AFBPlayerController>()->SetInputMode(FInputModeUIOnly());
		}
	}
}


