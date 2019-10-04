// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Healers_TargetType.h"
#include "Healers_GameplayAbility.h"
#include "Healers_Character.h"

void UHealers_TargetType::GetTargets_Implementation(AHealers_Character* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const
{
	return;
}

void UHealers_TargetType_UseOwner::GetTargets_Implementation(AHealers_Character* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const
{
	OutActors.Add(TargetingCharacter);
}

void UHealers_TargetType_UseEventData::GetTargets_Implementation(AHealers_Character* TargetingCharacter, AActor* TargetingActor, FGameplayEventData EventData, TArray<FHitResult>& OutHitResults, TArray<AActor*>& OutActors) const
{
	const FHitResult* FoundHitResult = EventData.ContextHandle.GetHitResult();
	if (FoundHitResult)
	{
		OutHitResults.Add(*FoundHitResult);
	}
	else if (EventData.Target)
	{
		OutActors.Add(const_cast<AActor*>(EventData.Target));
	}
}