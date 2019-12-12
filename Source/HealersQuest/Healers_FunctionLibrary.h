// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "HealersQuest.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Healers_FunctionLibrary.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward declarations

class AHealers_GameMode;
class UDataTable;

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

    // Get Enum as String - For printing
    UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString"), Category = "Healers|Enum")
    FORCEINLINE FString GetEnumAsString_ECharacterProfession(const ECharacterProfession Value)
    {
        const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ECharacterProfession"), true);
        if (!enumPtr)
        {
            return FString("Invalid");
        }
        return enumPtr->GetNameByValue(static_cast<int64>(Value)).ToString();
    }

    UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString"), Category = "Healers|Enum")
    FORCEINLINE FString GetEnumAsString_ECharacterRace(const ECharacterRace Value)
    {
        const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ECharacterRace"), true);
        if (!enumPtr)
        {
            return FString("Invalid");
        }
        return enumPtr->GetNameByValue(static_cast<int64>(Value)).ToString();
    }

    template<typename TEnum>
    static FORCEINLINE FString GetEnumValueAsString(const FString& Name, TEnum Value)
    {
        const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
        if (!enumPtr)
        {
            return FString("Invalid");
        }
        return enumPtr->GetNameByValue(static_cast<int64>(Value)).ToString();
    }
};
