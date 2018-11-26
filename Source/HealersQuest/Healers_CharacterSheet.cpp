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

void AHealers_CharacterSheet::AddSpellEffect(AHealers_Spell* spell)
{
    if (spell != nullptr)
    {
        if (!activeEffects.Contains(spell))
            activeEffects.Add(spell);
        else
        {
            //psudo
            //if (spell.isStackable)
            //    activeEffects.Add(spell);
            //else
            //    //error?
        }
    }
}

AHealers_CharacterSheet* AHealers_CharacterSheet::GetCharacterSheet(APawn* sheetOwner)
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
                    AddAttributes(CurrentRow->Attributes);
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
                    AddAttributes(CurrentRow->Attributes);
                    break;
                }
            }
        }
    }
}

void AHealers_CharacterSheet::AddAttributes(const FCharacterAttributes& InAttributes)
{
    CharacterSheet.Attributes.Health += InAttributes.Health;
    CharacterSheet.Attributes.HealthMax += FMath::Max(InAttributes.HealthMax, InAttributes.Health);
    CharacterSheet.Attributes.Mana += InAttributes.Mana;
    CharacterSheet.Attributes.ManaMax += FMath::Max(InAttributes.ManaMax, InAttributes.Mana);
    CharacterSheet.Attributes.ManaRegenerationPerSecond += InAttributes.ManaRegenerationPerSecond;
    CharacterSheet.Attributes.InitiativePerSecond += InAttributes.InitiativePerSecond;

    CharacterSheet.Attributes.AttackAccuracy += InAttributes.AttackAccuracy;
    CharacterSheet.Attributes.AttackPower += InAttributes.AttackPower;
    CharacterSheet.Attributes.MagicAccuracy += InAttributes.MagicAccuracy;
    CharacterSheet.Attributes.MagicPower += InAttributes.MagicPower;

    CharacterSheet.Attributes.CriticalDamageChance += InAttributes.CriticalDamageChance;
    CharacterSheet.Attributes.CriticalDamageValue += InAttributes.CriticalDamageValue;

    CharacterSheet.Attributes.EvasionValue += InAttributes.EvasionValue;
    CharacterSheet.Attributes.ArmorValue += InAttributes.ArmorValue;

    CharacterSheet.Attributes.LuckValue += InAttributes.LuckValue;

    for (auto InResistanceEntry : InAttributes.Resistances)
    {   
        bool IsPresent = false;
        for (auto& ResistanceEntry : CharacterSheet.Attributes.Resistances)
        {
            if ((int32)ResistanceEntry.DamageType == (int32)InResistanceEntry.DamageType)
            {
                IsPresent = true;
                ResistanceEntry.DamageResistancePercentValue += InResistanceEntry.DamageResistancePercentValue;
                ResistanceEntry.DamageResistanceValue += InResistanceEntry.DamageResistanceValue;
                break;
            }
        }

        if (!IsPresent)
        {
            // @! TODO : Use AddUnique, but need to define FDamageResistance equals operator
            CharacterSheet.Attributes.Resistances.Add(InResistanceEntry);
        }
    }

    for (auto InAbilityEntry : InAttributes.Abilities)
    {
        bool IsPresent = false;
        for (auto& AbilityEntry : CharacterSheet.Attributes.Abilities)
        {
            // @! TODO Need a Name property for Abilities/Spells
            if (false) //if (AbilityEntry.Name == InAbilityEntry.Name)
            {
                IsPresent = true;
                //
                break;
            }
        }

        if (!IsPresent)
        {
            CharacterSheet.Attributes.Abilities.AddUnique(InAbilityEntry);
        }
    }

    CharacterSheet.Attributes.MagicPower += InAttributes.MagicPower;
}
