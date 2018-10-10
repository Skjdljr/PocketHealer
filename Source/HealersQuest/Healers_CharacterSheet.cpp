

#include "Healers_CharacterSheet.h"


AHealers_CharacterSheet::AHealers_CharacterSheet()
{
	CharacterName = FString("Uninitialized");
	Race = ECharacterRace::RACE_None;

}

void AHealers_CharacterSheet::BeginPlay()
{
	Super::BeginPlay();

	InitializeCharacter();
}

void AHealers_CharacterSheet::InitializeCharacter()
{

	// Initialize Health. Linear growth by Profession per-level value.
	Health = HealthBase;
	for (auto Profession : ProfessionData)
	{
		Health += Profession.Profession.Health;
	}
	HealthMax = Health;

	// Initialize Mana. Linear growth by Profession per-level value.
	Mana = ManaBase;
	for (auto Profession : ProfessionData)
	{
		Mana += Profession.Profession.Mana;
	}
	ManaMax = Mana;

	// Average by Profession.
	int32 TotalLevels = 0;
	for (auto Profession : ProfessionData)
	{
		ManaRegenerationPerSecond += Profession.Profession.ManaRegenerationPerSecondValue * Profession.Count;
		TotalLevels += Profession.Count;
	}
	ManaRegenerationPerSecond /= TotalLevels;
	ManaRegenerationPerSecond += ManaRegenerationPerSecondBase;

}
