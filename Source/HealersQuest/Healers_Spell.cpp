// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_Spell.h"
#include "Healers_CharacterSheet.h"
#include "Healers_SpellComponent.h"
#include "Healers_SpellPrerequisiteComponent.h"
#include "Healers_SpellTargetingComponent.h"
#include "HealersQuest.h"

AHealers_Spell::AHealers_Spell(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AHealers_Spell::BeginPlay ()
{
	Super::BeginPlay();

	GetComponents(OUT SpellComponents);
	GetComponents(OUT Prerequisites);

	TargetComponent = FindComponentByClass<UHealers_SpellTargetingComponent>();
}

void AHealers_Spell::Destroyed ()
{
	for (int i = 0; i < SpellComponents.Num(); ++i)
	{
		SpellComponents[i]->DestroySpellComponent();
	}

	Super::Destroyed();
}

void AHealers_Spell::Tick (float deltaSec)
{
	Super::Tick(deltaSec);

	for (int i = 0; i < SpellComponents.Num(); ++i)
	{
		SpellComponents[i]->TickSpell(deltaSec);
	}
}

bool AHealers_Spell::CanCastSpell (AHealers_CharacterSheet* caster) const
{
	for (int i = 0; i < Prerequisites.Num(); ++i)
	{
		if (!Prerequisites[i]->CanCastSpell(caster))
		{
			return false;
		}
	}

	//Can't cast it again if it's already active
	for (int i = 0; i < SpellComponents.Num(); ++i)
	{
		if (SpellComponents[i]->IsSpellActive())
		{
			return false;
		}
	}

	return true;
}

bool AHealers_Spell::CanCastSpellOnTargets(AHealers_CharacterSheet* caster, const TArray<AActor*>& targets) const
{
	for (int i = 0; i < Prerequisites.Num(); ++i)
	{
		if (!Prerequisites[i]->CanCastSpellOnTargets(caster, targets))
		{
			return false;
		}
	}

	return true;
}

void AHealers_Spell::CastSpell(AHealers_CharacterSheet* caster, const TArray<AActor*>& targets)
{
	for (int i = 0; i < Prerequisites.Num(); ++i)
	{
		Prerequisites[i]->SpellExecuted(caster);
	}

	for (int i = 0; i < SpellComponents.Num(); ++i)
	{
		SpellComponents[i]->ExecuteSpell(this, caster, targets);
	}
}