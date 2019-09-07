// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once


#include "AbilitySystemComponent.h"

#include "HealersQuest.h"
#include "Healers_AbilityTypes.h"
#include "Healers_AbilitySystemComponent.generated.h"

/**
 * Subclass of ability system component with game-specific data
 * Game-specific subclass to provide utility functions
 */
UCLASS()
class HEALERSQUEST_API UHealers_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	// Constructors and overrides
	UHealers_AbilitySystemComponent();

	/** Returns a list of currently active ability instances that match the tags */
	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<UGameplayAbility*>& ActiveAbilities);

	/** Returns the default level used for ability activations, derived from the character */
	int32 GetDefaultAbilityLevel() const;

	/** Version of function in AbilitySystemGlobals that returns correct type */
	static UHealers_AbilitySystemComponent* GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent = false);
};