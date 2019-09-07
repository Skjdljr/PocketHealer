// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Healers_AbilityTypes.h"

#include "HealersQuest.h"
#include "Healers_AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"

bool FHealers_GameplayEffectContainerSpec::HasValidEffects() const
{
	return TargetGameplayEffectSpecs.Num() > 0;
}

bool FHealers_GameplayEffectContainerSpec::HasValidTargets() const
{
	return TargetData.Num() > 0;
}

void FHealers_GameplayEffectContainerSpec::AddTargets(const TArray<FHitResult>& HitResults, const TArray<AActor*>& TargetActors)
{
	for (const FHitResult& HitResult : HitResults)
	{
		FGameplayAbilityTargetData_SingleTargetHit* NewData = new FGameplayAbilityTargetData_SingleTargetHit(HitResult);
		TargetData.Add(NewData);
	}

	if (TargetActors.Num() > 0)
	{
		FGameplayAbilityTargetData_ActorArray* NewData = new FGameplayAbilityTargetData_ActorArray();
		NewData->TargetActorArray.Append(TargetActors);
		TargetData.Add(NewData);
	}
}