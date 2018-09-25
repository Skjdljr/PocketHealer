

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Healers_FunctionLibrary.generated.h"

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
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Healers|Random")
	static bool IsRandomSuccess(const float BaseChance, const int32 Counter);
};
