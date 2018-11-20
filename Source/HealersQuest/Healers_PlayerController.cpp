// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_PlayerController.h"
#include "HealersQuest.h"
#include "Engine/World.h"

//UMG
#include "SlateBasics.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

#include "Components/AudioComponent.h"

AHealers_PlayerController::AHealers_PlayerController()
{
    MusicVolumeScalar = 1.0;
    MusicComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("MusicComponent"));
    MusicComponent->SetupAttachment(RootComponent);
}

void AHealers_PlayerController::BeginPlay()
{
    Super::BeginPlay();

    FInputModeGameAndUI InputMode;
    InputMode.SetHideCursorDuringCapture(false);
    SetInputMode(InputMode);
}

void AHealers_PlayerController::PlayMusic(USoundBase * Music, float FadeInDuration)
{
    if (MusicComponent)
    {
        MusicComponent->SetSound(Music);
        MusicComponent->FadeIn(FadeInDuration, MusicVolumeScalar);
    }
}

void AHealers_PlayerController::StopMusic(float FadeOutDuration)
{
    if (MusicComponent)
    {
        MusicComponent->FadeOut(FadeOutDuration, 0.f);
    }
}

void AHealers_PlayerController::SetMusicVolume(float MusicVolume)
{
    MusicVolumeScalar = MusicVolume;
    if (MusicComponent)
    {
        MusicComponent->AdjustVolume(0.f, MusicVolumeScalar);
    }
}
