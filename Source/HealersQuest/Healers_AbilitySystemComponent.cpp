// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Healers_AbilitySystemComponent.h"

//#include "Abilities/RPGGameplayAbility.h"
#include "AbilitySystemGlobals.h"

#include "Healers_Character.h"

UHealers_AbilitySystemComponent::UHealers_AbilitySystemComponent()
{
}

void UHealers_AbilitySystemComponent::GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<UGameplayAbility*>& ActiveAbilities)
{
    TArray<FGameplayAbilitySpec*> AbilitiesToActivate;
    GetActivatableGameplayAbilitySpecsByAllMatchingTags(GameplayTagContainer, AbilitiesToActivate, false);

    // Iterate the list of all ability specs
    for (FGameplayAbilitySpec* Spec : AbilitiesToActivate)
    {
        // Iterate all instances on this ability spec
        TArray<UGameplayAbility*> AbilityInstances = Spec->GetAbilityInstances();

        for (UGameplayAbility* ActiveAbility : AbilityInstances)
        {
            ActiveAbilities.Add(Cast<UGameplayAbility>(ActiveAbility));
        }
    }
}

int32 UHealers_AbilitySystemComponent::GetDefaultAbilityLevel() const
{
    AHealers_Character* OwningCharacter = Cast<AHealers_Character>(OwnerActor);

    if (OwningCharacter)
    {
        //return OwningCharacter->GetCharacterLevel();
    }
    return 1;
}

UHealers_AbilitySystemComponent* UHealers_AbilitySystemComponent::GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent)
{
    return Cast<UHealers_AbilitySystemComponent>(UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor, LookForComponent));
}
