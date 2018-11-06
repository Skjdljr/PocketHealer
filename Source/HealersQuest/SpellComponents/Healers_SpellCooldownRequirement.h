// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Healers_SpellPrerequisiteComponent.h"
#include "Healers_SpellCooldownRequirement.generated.h"

class AHealers_Spell;
class AHealers_CharacterSheet;

UCLASS(Blueprintable, BlueprintType, Category="Healers", meta=(BlueprintSpawnableComponent))
class HEALERSQUEST_API UHealers_SpellCooldownRequirement : public UHealers_SpellPrerequisiteComponent
{
    GENERATED_BODY()

public:
	/* Number of seconds that must elapse before this spell can be casted again. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Healers")
	float SpellCastInterval;

	/* Number of seconds remaining before this spell becomes available again.
	If negative, then this spell is ready. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Healers")
	float Cooldown;

	/* Multiplier in how fast the cooldown depletes (think alacrity) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Healers")
	float CooldownMultiplier;

    UHealers_SpellCooldownRequirement(const FObjectInitializer& ObjectInitializer);

	virtual bool CanCastSpell(AHealers_CharacterSheet* caster) const override;
	virtual void SpellExecuted(AHealers_CharacterSheet* caster) override;
	virtual void TickPrerequisite(float deltaSec) override;
};
