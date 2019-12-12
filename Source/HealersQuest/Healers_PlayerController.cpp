// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

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

#include "Healers_GameInstance.h"
#include "Healers_SpellBar.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

AHealers_PlayerController::AHealers_PlayerController()
{
    bShowMouseCursor = true;

    MusicVolumeScalar = 1.0;
    MusicComponent    = CreateDefaultSubobject<UAudioComponent>(TEXT("MusicComponent"));
    MusicComponent->SetupAttachment(RootComponent);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void AHealers_PlayerController::BeginPlay()
{
    Super::BeginPlay();
    FInputModeGameAndUI InputMode;
    InputMode.SetHideCursorDuringCapture(false);
    SetInputMode(InputMode);
}

void AHealers_PlayerController::PlayMusic(USoundBase* Music, float FadeInDuration)
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

void AHealers_PlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("GameMenu", IE_Pressed, this, &AHealers_PlayerController::ToggleGameMenu);

    InputComponent->BindAction("CharacterMenu", IE_Pressed, this, &AHealers_PlayerController::ToggleCharacterMenu);

    InputComponent->BindAction("CombatAction1", IE_Pressed, this, &AHealers_PlayerController::CombatAction<1>);
    InputComponent->BindAction("CombatAction2", IE_Pressed, this, &AHealers_PlayerController::CombatAction<2>);
    InputComponent->BindAction("CombatAction3", IE_Pressed, this, &AHealers_PlayerController::CombatAction<3>);
    InputComponent->BindAction("CombatAction4", IE_Pressed, this, &AHealers_PlayerController::CombatAction<4>);
    InputComponent->BindAction("CombatAction5", IE_Pressed, this, &AHealers_PlayerController::CombatAction<5>);
    InputComponent->BindAction("CombatAction6", IE_Pressed, this, &AHealers_PlayerController::CombatAction<6>);
    InputComponent->BindAction("CombatAction7", IE_Pressed, this, &AHealers_PlayerController::CombatAction<7>);
    InputComponent->BindAction("CombatAction8", IE_Pressed, this, &AHealers_PlayerController::CombatAction<8>);
}

void AHealers_PlayerController::ToggleGameMenu()
{
    UE_LOG(Game, Log, TEXT("Key Pressed - Game Menu"));
    if (auto World = GetWorld())
    {
        if (auto GameInstance = Cast<UHealers_GameInstance>(World->GetGameInstance()))
        {
            if (auto GameMenu = GameInstance->GameMenu)
            {
                GameMenu->RemoveFromViewport();
                GameInstance->GameMenu = nullptr;
            }
            else
            {
                if (auto GameMenuClass = GameInstance->GameMenuClass)
                {
                    GameMenu = CreateWidget<UUserWidget>(World, GameMenuClass);
                    if (GameMenu)
                    {
                        //auto PC = World->GetFirstPlayerController();

                        GameMenu->AddToViewport();
                        GameInstance->GameMenu = GameMenu;
                    }
                }
            }
        }
    }
}

void AHealers_PlayerController::ToggleCharacterMenu()
{
    //AHealers_CharacterSheet* Sheet = AHealers_CharacterSheet::GetCharacterSheet(Pawn);

    //
    if (auto World = GetWorld())
    {
        if (auto GameInstance = Cast<UHealers_GameInstance>(World->GetGameInstance()))
        {
            if (auto CharacterMenu = GameInstance->CharacterMenu)
            {
                CharacterMenu->RemoveFromViewport();
                GameInstance->CharacterMenu = nullptr;
            }
            else
            {
                if (auto CharacterMenuClass = GameInstance->CharacterMenuClass)
                {
                    // TODO : Need an interface to open a window
                    CharacterMenu = CreateWidget<UUserWidget>(World, CharacterMenuClass);
                    if (CharacterMenu)
                    {
                        //auto PC = World->GetFirstPlayerController();

                        CharacterMenu->AddToViewport();
                        GameInstance->CharacterMenu = CharacterMenu;
                    }
                }
            }
        }
    }
}

void AHealers_PlayerController::CombatAction(int32 Index)
{
    UE_LOG(Game, Log, TEXT("<%s>(Line %i) : Key Pressed - CombatAction %i"), *FString(__FUNCTION__), __LINE__, Index);

    if (SpellBar && IsCombatActionAllowed())
    {
        //todo::FixSpellBar
        //SpellBar->SelectSpell(Index);
    }
}

bool AHealers_PlayerController::IsCombatActionAllowed_Implementation() const
{
    // TODO: Logic for when this is allowed.
    return true;
}
