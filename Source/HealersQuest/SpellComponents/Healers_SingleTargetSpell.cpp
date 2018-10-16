// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_SingleTargetSpell.h"

UHealers_SingleTargetSpell::UHealers_SingleTargetSpell(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	Target = nullptr;
}

TArray<AActor*> UHealers_SingleTargetSpell::GetTargets (APawn* caster) const
{
	TArray<AActor*> targets;
	if (Target != nullptr)
	{
		targets.Add(Target);
	}

	return targets;
}