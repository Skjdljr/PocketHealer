

#include "Healers_CharacterSheet.h"
#include "Engine/World.h"
// #include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/GameStateBase.h"
#include "Healers_PlayerState.h"
#include "Healers_GameMode.h"


AHealers_CharacterSheet::AHealers_CharacterSheet()
{
    // ConstructorHelpers::FObjectFinder<UDataTable> BP_RaceTable(TEXT("DataTable'/Game/Data/DT_CharacterRaces.DT_CharacterRaces'"));
    // RaceTable = BP_RaceTable.Object;
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
    const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ECharacterRace"), true);
    auto CharacterRaceString = EnumPtr->GetNameStringByIndex(CharacterSheet.Race.GetValue());
    
    // Use our GameMode's RaceTable and our CharacterRaceString as keys to retrieve FCharacterRaceDefinition values
    if (auto World = GetWorld())
    {
        if (auto GS = World->GetGameState())
        {
            if (auto GameModeClass = GS->GameModeClass)
            {
                if (auto GameModeDefaultObject = Cast<AHealers_GameMode>(GameModeClass->GetDefaultObject()))
                {
                    if (auto RaceDataTable = GameModeDefaultObject->CharacterRaceLibrary)
                    {
                        // Find the Row in the DataTable whose RowName(Key) matches our Race Enum value
                        if (auto RaceDefinition = RaceDataTable->FindRow<FCharacterRaceDefinition>(*CharacterRaceString, TEXT("Human")))
                        {
                            // Copy out our Race Data
                            //CharacterSheetData.Data = RaceDefinition->Attributes;
                        }
                        else
                        {
                            // There should be an error here.
                            // This implies we have an entry in our ECharacterRace enum that is missing a corresponding Row entry
                            // in our Race DataTable
                        }
                    }
                }
            }
        }
    }

    // Initialize Health. Linear growth by Profession per-level value.
    
    //auto LevelString = FString::FromInt(CharacterSheetData.Level);
    //if (CharacterSheetData.Profession.Profession->FindRow<FCharacterProfession>(*))
    //if (auto ProfessionRow = CharacterSheetData.Profession.Profession->FindRow<FCharacterProfession>(*LevelString, TEXT("1")))
    {
        //CharacterSheetData.Data.Health += ProfessionRow->Health;
        //CharacterSheetData.Data.Health +=
    }
    
    
    //for (auto Profession : ProfessionData)
    //{
    //	Health += Profession.Profession.Health;
    //}
    //Health += Profession.Attributes.Health;
    //HealthMax = Health;

    // Initialize Mana. Linear growth by Profession per-level value.

    //for (auto Profession : ProfessionData)
    //{
    //	Mana += Profession.Profession.Mana;
    //}
    //Mana += Profession.Attributes.Health;
    //ManaMax = Mana;

    // Average by Profession.
    /*
    int32 TotalLevels = 0;
    for (auto Profession : ProfessionData)
    {
        ManaRegenerationPerSecond += Profession.Profession.ManaRegenerationPerSecondValue * Profession.Count;
        TotalLevels += Profession.Count;
    }
    ManaRegenerationPerSecond /= TotalLevels;
    ManaRegenerationPerSecond += ManaRegenerationPerSecondBase;
    */

    //ManaRegenerationPerSecond += Profession.Attributes.ManaRegenerationPerSecond;
}
