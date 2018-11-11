#include "Healers_FunctionLibrary.h"

#include "Engine/DataTable.h"
#include "Engine/World.h"
#include "GameFramework/GameStateBase.h"

#include "Healers_CharacterAttributes.h"
#include "Healers_CharacterSheet.h"
#include "Healers_GameMode.h"
#include "Healers_PlayerController.h"
#include "Healers_PlayerState.h"
#include "Healers_PartySheet.h"

float UHealers_FunctionLibrary::PseudoRandomChance(float BaseChance, int32 Counter)
{
    float FinalChance = BaseChance;

    if (Counter > 1)
    {
        FinalChance += BaseChance * Counter;
    }

    return FinalChance;
}

bool UHealers_FunctionLibrary::IsRandomSuccess(const float BaseChance, const int32 Counter)
{
    bool IsSuccess = false;

    float ChanceValue = FMath::FRand();
    if (ChanceValue > PseudoRandomChance(BaseChance, Counter))
    {
        IsSuccess = true;
    }
    
    return IsSuccess;
}

AHealers_GameMode* UHealers_FunctionLibrary::GetGameModeDefaultObject(const UObject* WorldContextObject)
{
    AHealers_GameMode* GameModeDefaultObject = nullptr;
    
    if (auto World = WorldContextObject->GetWorld())
    {
        if (auto GS = World->GetGameState())
        {
            if (auto GameModeClass = GS->GameModeClass)
            {
                GameModeDefaultObject = Cast<AHealers_GameMode>(GameModeClass->GetDefaultObject());
            }
        }
    }

    return GameModeDefaultObject;
}

UDataTable* UHealers_FunctionLibrary::GetRaceDataTableFromLibrary(const UObject* WorldContextObject, ECharacterRace InRace)
{
    UDataTable* RaceTable = nullptr;

    if (auto GameModeDefaultObject = GetGameModeDefaultObject(WorldContextObject))
    {
        if (auto RaceLibrary = GameModeDefaultObject->CharacterRaceLibrary)
        {
            auto RaceRowNames = RaceLibrary->GetRowNames();
            for (auto& CurrentRowName : RaceRowNames)
            {
                FString OutErrorMessage;
                if (auto CurrentRow = RaceLibrary->FindRow<FCharacterRaceLibrary>(CurrentRowName, OutErrorMessage))
                {
                    // If our Race Enums Match
                    if (InRace == CurrentRow->Race)
                    {
                        RaceTable = CurrentRow->DataTable;
                        break;
                    }
                }
                else
                {
                    // Log - OutErrorMessage
                }
            }

            if (RaceTable == nullptr)
            {
                // Error - Found no matching Race in RaceLibrary. Library out of date?
            }
        }
    }

    return RaceTable;
}

UDataTable* UHealers_FunctionLibrary::GetProfessionDataTableFromLibrary(const UObject* WorldContextObject, ECharacterProfession InProfession)
{
    UDataTable* ProfessionTable = nullptr;

    if (auto GameModeDefaultObject = GetGameModeDefaultObject(WorldContextObject))
    {
        if (auto ProfessionLibrary = GameModeDefaultObject->CharacterProfessionLibrary)
        {
            auto RaceRowNames = ProfessionLibrary->GetRowNames();
            for (auto& CurrentRowName : RaceRowNames)
            {
                FString OutErrorMessage;
                if (auto CurrentRow = ProfessionLibrary->FindRow<FCharacterProfessionLibrary>(CurrentRowName, OutErrorMessage))
                {
                    // If our Race Enums Match
                    if (InProfession == CurrentRow->Profession)
                    {
                        ProfessionTable = CurrentRow->DataTable;
                        break;
                    }
                }
                else
                {
                    // Error - OutErrorMessage
                }
            }

            if (ProfessionTable == nullptr)
            {
                // Error - Found no matching Profession in ProfessionLibrary. Library out of date?
            }
        }
    }

    return ProfessionTable;
}

AHealers_PartySheet* UHealers_FunctionLibrary::GetPartySheet(APlayerController* PlayerController)
{
    AHealers_PartySheet* PartySheet = nullptr;
    if (PlayerController)
    {
        if (auto PlayerState = Cast<AHealers_PlayerState>(PlayerController->PlayerState))
        {
            PartySheet = PlayerState->PartySheet;
        }
    }
    return PartySheet;
}

AHealers_CharacterSheet* UHealers_FunctionLibrary::GetPlayerCharacterSheet(APlayerController* PlayerController)
{
    AHealers_CharacterSheet* CharacterSheet = nullptr;
    if (PlayerController)
    {
        if (auto PlayerState = Cast<AHealers_PlayerState>(PlayerController->PlayerState))
        {
            CharacterSheet = PlayerState->PartySheet->PartyMembers[0];
        }
    }
    return CharacterSheet;
}
