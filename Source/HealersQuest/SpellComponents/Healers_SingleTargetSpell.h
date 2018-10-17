// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Healers_SpellTargetingComponent.h"
#include "Healers_SingleTargetSpell.generated.h"

class AHealers_Spell;

UCLASS(Blueprintable, BlueprintType, Category="Healers", meta=(BlueprintSpawnableComponent))
class HEALERSQUEST_API UHealers_SingleTargetSpell : public UHealers_SpellTargetingComponent
{
    GENERATED_BODY()

public:
	/* The single target the user has selected.  The UI is most likely going to set this variable. */
	AActor* Target;

    UHealers_SingleTargetSpell(const FObjectInitializer& ObjectInitializer);

	virtual TArray<AActor*> GetTargets (APawn* caster) const override;
};
