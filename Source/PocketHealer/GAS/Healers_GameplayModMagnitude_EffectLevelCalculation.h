// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "Healers_GameplayModMagnitude_EffectLevelCalculation.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 
 */
UCLASS()
class POCKETHEALER_API UHealers_GameplayModMagnitude_EffectLevelCalculation : public UGameplayModMagnitudeCalculation
{
    GENERATED_BODY()
    
public:

    float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const;
};
