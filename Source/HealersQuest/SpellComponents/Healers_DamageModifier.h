// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Healers_SpellComponent.h"
#include "Healers_CharacterSheet.h"
#include "Healers_DamageModifier.generated.h"

UCLASS(Blueprintable, BlueprintType, Category="Healers", meta=(BlueprintSpawnableComponent))
class HEALERSQUEST_API UHealers_DamageModifier : public UHealers_SpellComponent
{
    GENERATED_BODY()

public:
	/* List of resistances to modify when active.  Negative values associated with an element
	implies that the spell component increases the target's vulnerability, and positive values
	protects the targets. */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Healers")
	TArray<FDamageResistance> DamageModifiers;

	/* List of targets that are affected. */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Healers")
	TArray<AHealers_CharacterSheet*> Targets;

    UHealers_DamageModifier(const FObjectInitializer& ObjectInitializer);

	virtual void ExecuteSpell(AHealers_Spell* spellOwner, AHealers_CharacterSheet* caster, const TArray<AHealers_CharacterSheet*>& targets) override;
	virtual void ShutdownSpell () override;
	virtual void DestroySpellComponent () override;

protected:
	virtual void GiveDamageModifierToTarget (AActor* newTarget);
	virtual void RemoveDamageModifiers ();
};
