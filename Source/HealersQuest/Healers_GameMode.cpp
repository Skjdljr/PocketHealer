// Fill out your copyright notice in the Description page of Project Settings.

#include "HealersQuest.h"
#include "Healers_GameMode.h"
#include "Engine/World.h"

//UMG
#include "SlateBasics.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

AHealers_GameMode::AHealers_GameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
    // Set to true via MainMenu to start the game
	bDelayedStart = true;
}

void AHealers_GameMode::BeginPlay()
{
	Super::BeginPlay();

	if (auto world = GetWorld())
	{
		UE_LOG(Game, Log, TEXT("Simple Log"));

	    MainMenu = CreateWidget<UUserWidget>(world, MainMenuClass);
        if (MainMenu)
        {
            auto pc = world->GetFirstPlayerController();

            MainMenu->AddToViewport();
        }
		else if (ReadyToStartMatch())
		{
			StartMatch();
		}
	}
}