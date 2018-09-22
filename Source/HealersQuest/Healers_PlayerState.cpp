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


