// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"

#include "Healers_SpellTargetingComponent.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

class AHealers_CharacterSheet;

/////////////////////////////////////////////////////////////////////////////////////////////////

UCLASS(blueprintable)
class HEALERSQUEST_API UHealers_SpellTargetingComponent : public UActorComponent
{
    GENERATED_UCLASS_BODY()

public:
    /**
     * Populates a list of actors this spell will affect.
     * Examples:  All hostiles, single target, environment, all undead
     */
    virtual TArray<AHealers_CharacterSheet*> GetTargets (AHealers_CharacterSheet* caster) const;
};