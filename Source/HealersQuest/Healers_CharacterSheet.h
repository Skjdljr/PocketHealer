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
UCLASS(Blueprintable, BlueprintType, NotPlaceable)
class HEALERSQUEST_API AHealers_CharacterSheet : public AInfo
{
    GENERATED_BODY()

public:

    AHealers_CharacterSheet();

    virtual void BeginPlay();

    UFUNCTION(BlueprintCallable, Category = "CharacterSheet")
    void InitializeCharacter();

    UFUNCTION()
    void InitializeRaceAttributes(UDataTable* CharacterRaceDataTable);
    
    UFUNCTION()
    void InitializeProfessionAttributes(UDataTable* CharacterProfessionDataTable);
    
    UFUNCTION()
    void AddAttributes(const FCharacterAttributes& InAttributes);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true), Category = "CharacterSheet")
    FCharacterSheet CharacterSheet;

    UPROPERTY(BlueprintReadWRite, EditAnywhere, Category = "CharacterSheet")
    AHealers_Spell* CurrentSelectedSpell;

    /**
    * Getter and Setters
    */

    // Name
    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character Name"), Category = "CharacterSheet")
    FString GetCharacterName() const { return CharacterSheet.CharacterName; }

    UFUNCTION(BlueprintCallable, meta = (Keywords = "Character Name"), Category = "CharacterSheet")
    void SetCharacterName(const FString& InName) { CharacterSheet.CharacterName = InName; }

    // Race
    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character Race"), Category = "CharacterSheet")
    TEnumAsByte<ECharacterRace> GetRace() const { return CharacterSheet.Race; }

    // Profession
    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character Profession"), Category = "CharacterSheet")
    TEnumAsByte<ECharacterProfession> GetProfession() const { return CharacterSheet.Profession; }

    // Attributes
    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character Attributes"), Category = "CharacterSheet")
    FCharacterAttributes& GetAttributes() { return CharacterSheet.Attributes; }

    // Level
    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character Level"), Category = "CharacterSheet")
    int32 GetCharacterLevel() const { return CharacterSheet.Level; }

    UFUNCTION(BlueprintCallable, meta = (Keywords = "Character Level"), Category = "CharacterSheet")
    void SetLevel(int32 InLevel) { CharacterSheet.Level = InLevel; }

    // Experience
    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character Experience"), Category = "CharacterSheet")
    float GetExperience() const { return CharacterSheet.Experience; }

    UFUNCTION(BlueprintCallable, meta = (Keywords = "Character Experience"), Category = "CharacterSheet")
    void SetExperience(float InExperience) { CharacterSheet.Experience = InExperience; }

    //Initiative
    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character Initiative"), Category = "CharacterSheet")
    float GetInitiative() const { return CharacterSheet.Attributes.Initiative; }

    UFUNCTION(BlueprintCallable, meta = (Keywords = "Character Initiative"), Category = "CharacterSheet")
    void SetInitiative(float inInit) { CharacterSheet.Attributes.Initiative = inInit; }

    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character InitiativePerSecond"), Category = "CharacterSheet")
    float GetInitiativePerSecond() const { return CharacterSheet.Attributes.InitiativePerSecond; }

    // Health
    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character Health"), Category = "CharacterSheet")
    float GetHealth() const { return CharacterSheet.Attributes.Health; }

    UFUNCTION(BlueprintCallable, meta = (Keywords = "Character Health"), Category = "CharacterSheet")
    void SetHealth(float InHealth) { CharacterSheet.Attributes.Health = InHealth; }

    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character HealthMax"), Category = "CharacterSheet")
    float GetHealthMax() const { return CharacterSheet.Attributes.HealthMax; }

    // Mana
    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character Mana"), Category = "CharacterSheet")
    float GetMana() const { return CharacterSheet.Attributes.Mana; }

    UFUNCTION(BlueprintCallable, meta = (Keywords = "Character Mana"), Category = "CharacterSheet")
    void SetMana(float InMana) { CharacterSheet.Attributes.Mana = InMana; }

    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character ManaMax"), Category = "CharacterSheet")
    float GetManaMax() const { return CharacterSheet.Attributes.ManaMax; }

    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character ManaRegeneration"), Category = "CharacterSheet")
    float GetManaRegenerationPerSecond() const { return CharacterSheet.Attributes.ManaRegenerationPerSecond; }

    // Resistances
    UFUNCTION(BlueprintPure, BlueprintCallable, meta = (Keywords = "Character Resistances"), Category = "CharacterSheet")
    TArray<FDamageResistance>& GetResistances() { return CharacterSheet.Attributes.Resistances; }

    /**
     * Convenience function to find a character sheet associated with a pawn.
     */
    UFUNCTION(BlueprintPure, BlueprintCallable, Category="Healers")
    static AHealers_CharacterSheet* GetCharacterSheet (APawn* sheetOwner);
};


// @! TODO : Need a good way of defining item properties. Suggested: Use GameplayTags. Tags: Weapon, Armor, Accessory, Consumable, etc.
// @! TODO : If using gameplay tags, how do we define what items can exist on a character? (e.g. if we had 'Tail' armor slot available only to enemies with 'Tail' tag, how do we define valid tags for each character? List of tags per CharacterSheet?)
//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
//TArray<AHealers_Inventory*> CharacterInventory;