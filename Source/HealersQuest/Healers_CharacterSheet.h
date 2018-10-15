

#pragma once

#include "CoreMinimal.h"
#include "HealersQuest.h"
#include "Engine/DataTable.h"
#include "GameFramework/Info.h"
#include "Healers_CharacterSheet.generated.h"


USTRUCT(BlueprintType)
struct FDamageResistance
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|DamageResistance")
	TEnumAsByte<EDamageResistance> DamageType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|DamageResistance")
	float DamageResistanceValue;
};

USTRUCT(BlueprintType, Blueprintable)
struct FCharacterProfession : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
	int32 Level;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
	FString ProfessionName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
	float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
	float Mana;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
	float ManaRegenerationPerSecondValue;
};

USTRUCT(BlueprintType, Blueprintable)
struct FCharacterProfessionData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
	FCharacterProfession Profession;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Profession")
	int32 Count;
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

	virtual void BeginPlay();

	UFUNCTION(BlueprintCallable, Category = "CharacterSheet")
	void InitializeCharacter();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ExposeOnSpawn = true), Category = "Healers|CharacterSheet")
	FString CharacterName;

	// Placeholder for Now
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ExposeOnSpawn = true), Category = "Healers|CharacterSheet")
	TEnumAsByte<ECharacterRace> Race;

	// Array of ProfessionData. Each level add an entry for each profession taken. Done this way to allow multiclassing Fighter 5/Wizard 1, etc.
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ExposeOnSpawn = true), Category = "Healers|CharacterSheet")
	TArray<FCharacterProfessionData> ProfessionData;

	//UFUNCTION(BlueprintCallable, Category = "Healers|CharacterSheet")
	//FORCEINLINE int32 GetCharacterLevel() const { return Classes.Num(); };

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ExposeOnSpawn = true), Category = "Healers|CharacterSheet")
	float Experience;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Healers|CharacterSheet")
	float HealthBase = 150;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float HealthMax;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ExposeOnSpawn = true), Category = "Healers|CharacterSheet")
	float ManaBase = 50;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float Mana;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float ManaMax;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Meta = (ExposeOnSpawn = true), Category = "Healers|CharacterSheet")
	float ManaRegenerationPerSecondBase = 1.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float ManaRegenerationPerSecond;


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float ArmorValue;

	// Initiative Gained per Second
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float BaseInitiativePerSecond;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float BaseAttackAccuracy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float BaseCriticalDamageChance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float BaseCriticalDamageValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|CharacterSheet")
	float BaseEvasionValue;


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
