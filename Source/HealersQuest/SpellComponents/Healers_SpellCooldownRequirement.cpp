// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_SpellCooldownRequirement.h"
#include "Healers_CharacterSheet.h"
#include "GameFramework/Pawn.h"

UHealers_SpellCooldownRequirement::UHealers_SpellCooldownRequirement(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	Cooldown = -1.f;
	CooldownMultiplier = 1.f;
}

bool UHealers_SpellCooldownRequirement::CanCastSpell(AHealers_CharacterSheet* caster) const
{
	return (Super::CanCastSpell(caster) && Cooldown <= 0.f);
}

void UHealers_SpellCooldownRequirement::SpellExecuted(AHealers_CharacterSheet* caster)
{
	Super::SpellExecuted(caster);

	Cooldown = SpellCastInterval;
}

void UHealers_SpellCooldownRequirement::TickPrerequisite(float deltaSec)
{
	Super::TickPrerequisite(deltaSec);

	if (Cooldown >= 0.f)
	{
		Cooldown -= (deltaSec * CooldownMultiplier);
	}
}