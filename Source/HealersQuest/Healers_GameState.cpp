// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_GameState.h"
#include "HealersQuest.h"
#include "Engine/World.h"

void AHealers_GameState::OnRep_MatchState()
{
	OnMatchStateChanged.Broadcast();
	
	Super::OnRep_MatchState();
}