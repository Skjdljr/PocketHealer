// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_GameMode.h"
#include "HealersQuest.h"
#include "Engine/World.h"

//UMG
#include "SlateBasics.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

#include "Healers_Character.h"
#include "Healers_PlayerController.h"
#include "Healers_HUD.h"
#include "Healers_GameInstance.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

AHealers_GameMode::AHealers_GameMode() :
    CharacterRaceLibrary(nullptr),
    DefaultStartingGold(0),
    DefaultStartingReputation(0),
    BattleCoordinator(nullptr)
{
    // Set to true via MainMenu to start the game
    bDelayedStart = true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void AHealers_GameMode::BeginPlay()
{
    Super::BeginPlay();

    if (auto World = GetWorld())
    {
        UE_LOG(Game, Log, TEXT("Simple Log"));

        if (auto GameInstance = Cast<UHealers_GameInstance>(World->GetGameInstance()))
        {
            if (auto MainMenuClass = GameInstance->MainMenuClass)
            {
                if (GameState)
                {
                    for (auto PlayerState : GameState->PlayerArray)
                    {
                        if (auto HealersPC = Cast<AHealers_PlayerController>(PlayerState->GetOwner()))
                        {
                            if (auto HealersHUD = Cast<AHealers_HUD>(HealersPC->GetHUD()))
                            {
                                HealersHUD->SetScene(MainMenuClass);
                            }
                        }
                    }
                }
            }
        }

        if (ReadyToStartMatch())
        {
            StartMatch();
        }
    }
}

void AHealers_GameMode::StartMatch()
{
    // Display World Map / Tavern / whatever UI
    
    AGameMode::StartMatch();
}

void AHealers_GameMode::BP_StartMatch()
{
    // AGameMode.Tick detects this and begins the match
    bDelayedStart = false;
}