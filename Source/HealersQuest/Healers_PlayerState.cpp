// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_PlayerState.h"
#include "Healers_PartySheet.h"
#include "Engine/World.h"

AHealers_PlayerState::AHealers_PlayerState()
{
	if (PartySheet)
	{
		if (auto World = GetWorld())
		{
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Owner = this;
			SpawnParameters.Instigator = Instigator;

			PartySheet = World->SpawnActor<AHealers_PartySheet>(SpawnParameters);
		}
	}
}

AHealers_CharacterSheet * AHealers_PlayerState::GetHealersCharacterSheet() const
{
	AHealers_CharacterSheet* Sheet = nullptr;
	if (PartySheet)
	{
		if (PartySheet->PartyMembers.Num() > 0)
		{
			// Player Character should always be Party Member at Index 0
			Sheet = PartySheet->PartyMembers[0];
		}
	}
	return nullptr;
}


