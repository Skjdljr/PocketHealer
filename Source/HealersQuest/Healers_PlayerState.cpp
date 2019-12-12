// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_PlayerState.h"
#include "Engine/World.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

AHealers_PlayerState::AHealers_PlayerState() :
    Gold(0),
    Reputation(0)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void AHealers_PlayerState::BeginPlay()
{
    //if (!PartySheet)
    {
        if (auto World = GetWorld())
        {
            FActorSpawnParameters SpawnParameters;
            SpawnParameters.Owner = this;
            SpawnParameters.Instigator = Instigator;

            //PartySheet = World->SpawnActor<AHealers_PartySheet>(SpawnParameters);
        }
    }
}


