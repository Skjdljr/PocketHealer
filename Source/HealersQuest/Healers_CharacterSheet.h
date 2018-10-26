#pragma once

#include "CoreMinimal.h"
#include "HealersQuest.h"
#include "Healers_Spell.h"
#include "Healers_CharacterAttributes.h"
#include "GameFramework/Info.h"
#include "Healers_CharacterSheet.generated.h"



/**
* FCharacterRace : Character Race Definition. Design-time structure stored in DataTable. 
*
*/
USTRUCT(BlueprintType, Blueprintable)
struct FCharacterRaceDefinition : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterRace")
    int32 Level;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterRace")
    FString RaceName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterRace")
    FCharacterAttributes Attributes;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
* FCharacterRaceLibrary : Character Race Library. Define DataTables used by each Race.
*
*/
USTRUCT(BlueprintType, Blueprintable)
struct FCharacterRaceLibrary : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
    TEnumAsByte<ECharacterRace> Race;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
    UDataTable* DataTable;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
* FCharacterProfessionDefinition : Character Profession Definition. Design-time structure stored in DataTable.
*
*/
USTRUCT(BlueprintType, Blueprintable)
struct FCharacterProfessionDefinition : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
    int32 Level;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
    FString ProfessionName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
    FCharacterAttributes Attributes;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
* FCharacterProfessionLibrary : Character Profession Library. Define DataTables used by each Profession.
*
*/
USTRUCT(BlueprintType, Blueprintable)
struct FCharacterProfessionLibrary : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
    TEnumAsByte<ECharacterProfession> Profession;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
    UDataTable* DataTable;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
* Obsolete - Only needed for Multiclass support.
* FCharacterProfessionLevel : Character Profession-Level. BP-Exposed structure storing set of Profession and Level.
*
*/
//USTRUCT(BlueprintType, Blueprintable)
//struct FCharacterProfessionLevel
//{
//    GENERATED_BODY()
//
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
//    TEnumAsByte<ECharacterProfession> Profession;
//
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
//    int32 Level;
//};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
* FCharacterSheet : Character Sheet. Design-time structure stored in DataTable.
*
*/
USTRUCT(BlueprintType, Blueprintable)
struct FCharacterSheet : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "CharacterSheet")
    FString CharacterName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "CharacterSheet")
    int32 Level;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "CharacterSheet")
    float Experience;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "CharacterSheet")
    TEnumAsByte<ECharacterRace> Race;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "CharacterSheet")
    TEnumAsByte<ECharacterProfession> Profession;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "CharacterSheet")
    FCharacterAttributes Attributes;

    // @! TODO: 
    // FCharacterInventory Inventory;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
* AHealers_CharacterSheet : Character Sheet Actor. Run-time instance of a CharacterSheet.
*
*/
UCLASS(Blueprintable)
class HEALERSQUEST_API AHealers_CharacterSheet : public AInfo
{
    GENERATED_BODY()

public:

    AHealers_CharacterSheet();

    virtual void BeginPlay();

    UFUNCTION(BlueprintCallable, Category = "CharacterSheet")
    void InitializeCharacter();

    void InitializeRaceAttributes(UDataTable* CharacterRaceDataTable);
    void InitializeProfessionAttributes(UDataTable* CharacterProfessionDataTable);
    void AddAttributes(const FCharacterAttributes& InAttributes);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "CharacterSheet")
    FCharacterSheet CharacterSheet;

    /**
    * Getter and Setters
    */

    // Race
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CharacterSheet")
    TEnumAsByte<ECharacterRace> GetCharacterRace() { return CharacterSheet.Race; }

    // Profession
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CharacterSheet")
    TEnumAsByte<ECharacterProfession> GetCharacterProfession() { return CharacterSheet.Profession; }

    // Attributes
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CharacterSheet")
    FCharacterAttributes& GetCharacterAttributes() { return CharacterSheet.Attributes; }

    // Level
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CharacterSheet")
    int32 GetLevel() { return CharacterSheet.Level; }

    UFUNCTION(BlueprintCallable, Category = "CharacterSheet")
    void SetLevel(int32 InLevel) { CharacterSheet.Level = InLevel; }

    // Experience
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CharacterSheet")
    float GetExperience() { return CharacterSheet.Experience; }

    UFUNCTION(BlueprintCallable, Category = "CharacterSheet")
    void SetExperience(float InExperience) { CharacterSheet.Experience = InExperience; }

    //Initiative
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CharacterSheet")
    float GetInitiative() { return CharacterSheet.Attributes.Initiative; }

    UFUNCTION(BlueprintCallable, Category = "CharacterSheet")
    void SetInitiative(float inInit) { CharacterSheet.Attributes.Initiative = inInit; }

    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CharacterSheet")
    float GetInitiativePerSecond() { return CharacterSheet.Attributes.InitiativePerSecond; }

    // Health
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CharacterSheet")
    float GetHealth() { return CharacterSheet.Attributes.Health; }

    UFUNCTION(BlueprintCallable, Category = "CharacterSheet")
    void SetHealth(float InHealth) { CharacterSheet.Attributes.Health = InHealth; }

    // Mana
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CharacterSheet")
    float GetMana() { return CharacterSheet.Attributes.Mana; }

    UFUNCTION(BlueprintCallable, Category = "CharacterSheet")
    void SetMana(float InMana) { CharacterSheet.Attributes.Mana = InMana; }

    // Resistances
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "CharacterSheet")
    TArray<FDamageResistance>& GetResistances() { return CharacterSheet.Attributes.Resistances; }

    /**
     * Convenience function to find a character sheet associated with a pawn.
     */
    UFUNCTION(BlueprintCallable, Category="Healers")
    static AHealers_CharacterSheet* GetCharacterSheet (APawn* sheetOwner);
};


// @! TODO : Need a good way of defining item properties. Suggested: Use GameplayTags. Tags: Weapon, Armor, Accessory, Consumable, etc.
// @! TODO : If using gameplay tags, how do we define what items can exist on a character? (e.g. if we had 'Tail' armor slot available only to enemies with 'Tail' tag, how do we define valid tags for each character? List of tags per CharacterSheet?)
//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
//TArray<AHealers_Inventory*> CharacterInventory;