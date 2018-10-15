

#include "Healers_CharacterSheet.h"
#include "Healers_PlayerState.h"
#include "GameFramework/Pawn.h"


AHealers_CharacterSheet::AHealers_CharacterSheet()
{
	CharacterName = FString("Uninitialized");
	Race = ECharacterRace::RACE_None;

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