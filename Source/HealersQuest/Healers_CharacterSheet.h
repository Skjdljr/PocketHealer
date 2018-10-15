

#pragma once

#include "CoreMinimal.h"
#include "HealersQuest.h"
#include "GameFramework/Info.h"
#include "Healers_CharacterSheet.generated.h"




USTRUCT(BlueprintType)
struct FDamageResistance
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|DamageResistance")
		TEnumAsByte<EDamageResistance> DamageType;

		UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|DamageResistance")
		float DamageResistanceValue;
};

/**
 * 
 */
UCLASS(Blueprintable) //Blueprintable
class HEALERSQUEST_API AHealers_CharacterSheet : public AActor //AInfo
{
	GENERATED_BODY()

public:

	AHealers_CharacterSheet();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	FString CharacterName;

	// Placeholder for Now
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	TEnumAsByte<ECharacterRace> Race;

	// @! TODO : Define a class for CharacterProfessions
	// Array of Professions. Each level add an entry for each profession taken. Done this way to allow multiclassing Fighter 5/Wizard 1, etc.
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	//TArray<ECharacterProfession> Professions;

	//UFUNCTION(BlueprintCallable, Category = "Healers|CharacterSheet")
	//FORCEINLINE int32 GetCharacterLevel() const { return Classes.Num(); };

	// @! TODO : Do we want Base Level Attributes? e.g.
	// Strength
	// Dexterity
	// Constitution
	// Spirit
	// Arcana

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float Experience;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float HealthMax;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float Mana;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float ManaMax;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float ArmorValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	TArray<FDamageResistance> Resistances;

	// @! TODO : Need a good way of defining item properties. Suggested: Use GameplayTags. Tags: Weapon, Armor, Accessory, Consumable, etc.
	// @! TODO : If using gameplay tags, how do we define what items can exist on a character? (e.g. if we had 'Tail' armor slot available only to enemies with 'Tail' tag, how do we define valid tags for each character? List of tags per CharacterSheet?)
	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	//TArray<AHealers_Inventory*> CharacterInventory;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	//TArray<AHealers_Ability*> Abilities;

	/**
	 * Convenience function to find a character sheet associated with a pawn.
	 */
	UFUNCTION(BlueprintCallable, Category="Healers")
	static AHealers_CharacterSheet* GetCharacterSheet (APawn* sheetOwner);
};
