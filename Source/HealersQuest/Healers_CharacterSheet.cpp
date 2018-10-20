#include "Healers_CharacterSheet.h"

#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/GameStateBase.h"
#include "Healers_GameMode.h"
#include "Healers_PlayerState.h"
#include "Healers_FunctionLibrary.h"


AHealers_CharacterSheet::AHealers_CharacterSheet()
{
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

void AHealers_CharacterSheet::BeginPlay()
{
    Super::BeginPlay();

    InitializeCharacter();
}

void AHealers_CharacterSheet::InitializeCharacter()
{
    // Using CharacterRace Enum, look up the String value for our character's Race
    // const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ECharacterRace"), true);
    // auto CharacterRaceString = EnumPtr->GetNameStringByIndex(CharacterSheet.Race.GetValue());
    
    // Use our RaceLibrary to find RaceDataTable corresponding to our RaceEnum
    if (auto CharacterRaceDataTable = UHealers_FunctionLibrary::GetRaceDataTableFromLibrary(this, CharacterSheet.Race))
    {
        InitializeRaceAttributes(CharacterRaceDataTable);
    }
    
    // Use our ProfessionLibrary to find DataTable matching our ProfessionEnum
    if (auto CharacterProfessionDataTable = UHealers_FunctionLibrary::GetProfessionDataTableFromLibrary(this, CharacterSheet.Profession))
    {
        InitializeProfessionAttributes(CharacterProfessionDataTable);
    }
}

void AHealers_CharacterSheet::InitializeRaceAttributes(UDataTable* CharacterRaceDataTable)
{
    if (CharacterRaceDataTable)
    {
        auto RowNames = CharacterRaceDataTable->GetRowNames();
        for (auto& CurrentRowName : RowNames)
        {
            auto CurrentRow = CharacterRaceDataTable->FindRow<FCharacterRaceDefinition>(CurrentRowName, FString());
            if (CurrentRow)
            {
                // @! NOTE For now, get the race data no matter what. In the future we might care about Race levels. 
                if (true || CharacterSheet.Level == CurrentRow->Level)
                {
                    // @! TODO : Add to base attributes instead of assign/copy...
                    CharacterSheet.Attributes = CurrentRow->Attributes;
                    break;
                }
            }
        }
    }
}

void AHealers_CharacterSheet::InitializeProfessionAttributes(UDataTable* CharacterProfessionDataTable)
{
    if (CharacterProfessionDataTable)
    {
        auto RowNames = CharacterProfessionDataTable->GetRowNames();
        for (auto& CurrentRowName : RowNames)
        {
            auto CurrentRow = CharacterProfessionDataTable->FindRow<FCharacterProfessionDefinition>(CurrentRowName, FString());
            if (CurrentRow)
            {
                // Get the entry for our Level
                if (CharacterSheet.Level == CurrentRow->Level)
                {
                    // @! TODO : Add to base attributes
                    // AddAttributes(CurrentRow->Attributes);
                    break;
                }
            }
        }
    }
}