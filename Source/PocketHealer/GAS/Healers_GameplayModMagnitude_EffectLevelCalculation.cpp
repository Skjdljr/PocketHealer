// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_GameplayModMagnitude_EffectLevelCalculation.h"

#include "../HealersQuest.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

float UHealers_GameplayModMagnitude_EffectLevelCalculation::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
    GAME_LOG(Game, Log, "GameplayEffect Level: %d", Spec.GetLevel());
    return Spec.GetLevel();
}