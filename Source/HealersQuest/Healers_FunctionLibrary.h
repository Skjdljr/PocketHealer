

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Healers_FunctionLibrary.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward declarations

class AHealers_CharacterSheet;
class AHealers_GameMode;
enum ECharacterRace;
enum ECharacterProfession;

/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API UHealers_FunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    // Simple implementation of pseudo-random chance algorithm for randomized events (e.g. critical hits)
    // See: https://dota2.gamepedia.com/Random_distribution for further details
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Healers|Random")
    static float PseudoRandomChance(const float BaseChance, const int32 Counter);
    
    // Passing a simple 
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Healers|Random") //Keywords = "Random Success",
    static bool IsRandomSuccess(const float BaseChance, const int32 Counter);

    // Utility for retrieving GameMode CDO
    static AHealers_GameMode* GetGameModeDefaultObject(const UObject* WorldContextObject);

    // Get a DataTable associated with a Race enum
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Healers|Library")
    static UDataTable* GetRaceDataTableFromLibrary(const UObject* WorldContextObject, ECharacterRace InRace);

    // Get a DataTable associated with a Profession enum
    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Healers|Library")
    static UDataTable* GetProfessionDataTableFromLibrary(const UObject* WorldContextObject, ECharacterProfession InProfession);

    // Get the PlayerController's PartySheet
    UFUNCTION(BlueprintPure, Category = "Healers|Party") //Keywords = "PartySheet", 
    static AHealers_PartySheet* GetPartySheet(APlayerController* PlayerController);

    UFUNCTION(BlueprintPure, Category = "Healers|Character|Sheet") 
    static AHealers_CharacterSheet* GetPlayerCharacterSheet(APlayerController* PlayerController);
};
