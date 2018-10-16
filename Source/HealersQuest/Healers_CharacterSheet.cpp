

#include "Healers_CharacterSheet.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Healers_PlayerState.h"
#include "GameFramework/Pawn.h"


AHealers_CharacterSheet::AHealers_CharacterSheet()
{
	CharacterName = FString("Uninitialized");
	Race = ECharacterRace::RACE_None;

	ConstructorHelpers::FObjectFinder<UDataTable> BP_RaceTable(TEXT("DataTable'/Game/Data/DT_CharacterRaces.DT_CharacterRaces'"));
	RaceTable = BP_RaceTable.Object;
}

AHealers_CharacterSheet* AHealers_CharacterSheet::GetCharacterSheet (APawn* sheetOwner)
{
	AHealers_PlayerState* healerState = Cast<AHealers_PlayerState>(sheetOwner->PlayerState);
	if (healerState == nullptr)
	{
		return nullptr;
	}

	return healerState->GetHealersCharacterSheet();
}

void AHealers_CharacterSheet::BeginPlay()
{
	Super::BeginPlay();

	InitializeCharacter();
}

void AHealers_CharacterSheet::InitializeCharacter()
{
	// Using CharacterRace Enum, get string value
	// RaceTable->FindRow() using string value
	// If we found a row, then our race attributes can be assigned to our base attributes

	// Initialize Health. Linear growth by Profession per-level value.
	
	Health = HealthBase;
	
	
	//for (auto Profession : ProfessionData)
	//{
	//	Health += Profession.Profession.Health;
	//}
	Health += Profession.Health;
	HealthMax = Health;

	// Initialize Mana. Linear growth by Profession per-level value.
	Mana = ManaBase;
	//for (auto Profession : ProfessionData)
	//{
	//	Mana += Profession.Profession.Mana;
	//}
	Mana += Profession.Mana;
	ManaMax = Mana;

	// Average by Profession.
	/*
	int32 TotalLevels = 0;
	for (auto Profession : ProfessionData)
	{
		ManaRegenerationPerSecond += Profession.Profession.ManaRegenerationPerSecondValue * Profession.Count;
		TotalLevels += Profession.Count;
	}
	ManaRegenerationPerSecond /= TotalLevels;
	ManaRegenerationPerSecond += ManaRegenerationPerSecondBase;
	*/

	ManaRegenerationPerSecond += Profession.ManaRegenerationPerSecondValue;

}
