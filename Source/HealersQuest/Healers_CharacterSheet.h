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
    FCharacterAttributes Attributes;
};




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




/**
* Obsolete - Only needed for Multiclass support.
* FCharacterProfessionLevel : Character Profession-Level. BP-Exposed structure storing set of Profession and Level.
*
*/
USTRUCT(BlueprintType, Blueprintable)
struct FCharacterProfessionLevel
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
    TEnumAsByte<ECharacterProfession> Profession;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
    int32 Level;
};




/**
* FCharacterSheet : Character Sheet. Design-time structure stored in DataTable.
*
*/
USTRUCT(BlueprintType, Blueprintable)
struct FCharacterSheet : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterSheet")
    FString CharacterName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterSheet")
    int32 Level;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterSheet")
    float Experience;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterSheet")
    TEnumAsByte<ECharacterRace> Race;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterSheet")
    TEnumAsByte<ECharacterProfession> Profession;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterSheet")
    FCharacterAttributes Attributes;

    // @! TODO: 
    // FCharacterInventory Inventory;
};




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

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterSheet")
    FCharacterSheet CharacterSheet;

    // @! TODO : Need a good way of defining item properties. Suggested: Use GameplayTags. Tags: Weapon, Armor, Accessory, Consumable, etc.
    // @! TODO : If using gameplay tags, how do we define what items can exist on a character? (e.g. if we had 'Tail' armor slot available only to enemies with 'Tail' tag, how do we define valid tags for each character? List of tags per CharacterSheet?)
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
    //TArray<AHealers_Inventory*> CharacterInventory;

    UFUNCTION(BlueprintCallable, Category = "CharacterSheet")
    TArray<FDamageResistance>& GetResistances() { return CharacterSheet.Attributes.Resistances; }

    /**
     * Convenience function to find a character sheet associated with a pawn.
     */
    UFUNCTION(BlueprintCallable, Category="Healers")
    static AHealers_CharacterSheet* GetCharacterSheet (APawn* sheetOwner);
};
