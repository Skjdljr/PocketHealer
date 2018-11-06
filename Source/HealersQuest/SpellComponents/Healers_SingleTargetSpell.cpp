// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_SingleTargetSpell.h"
#include "Healers_CharacterSheet.h"

UHealers_SingleTargetSpell::UHealers_SingleTargetSpell(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	Target = nullptr;
}

TArray<AHealers_CharacterSheet*> UHealers_SingleTargetSpell::GetTargets (AHealers_CharacterSheet* caster) const
{
	TArray<AHealers_CharacterSheet*> targets;
	if (Target != nullptr)
	{
		targets.Add(Target);
	}

	return targets;
}