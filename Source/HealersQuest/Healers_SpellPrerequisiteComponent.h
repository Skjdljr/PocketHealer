// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Healers_SpellPrerequisiteComponent.generated.h"

class AHealers_Spell;

UCLASS(blueprintable)
class HEALERSQUEST_API UHealers_SpellPrerequisiteComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UHealers_SpellPrerequisiteComponent(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category="Healers")
	virtual bool CanCastSpell(APawn* caster) const;

	UFUNCTION(BlueprintCallable, Category="Healers")
	virtual bool CanCastSpellOnTargets(APawn* caster, const TArray<AActor*>& targets) const;

	/**
	 * Invoked once a spell is executed.
	 * Used to deduct mana cost, reset cooldowns, etc...
	 */
	UFUNCTION(BlueprintCallable, Category="Healers")
	virtual void SpellExecuted(APawn* caster);

	/**
	 * Invoked every frame.  Allows prerequisites to continuously check and update their values
	 * regardless if a spell is active or not.
	 */
	virtual void TickPrerequisite (float deltaSec);
};
