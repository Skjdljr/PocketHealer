// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_SpellComponent.h"
#include "Healers_CharacterSheet.h"

void UHealers_SpellComponent::ExecuteSpell(AHealers_Spell* spellOwner, AHealers_CharacterSheet* caster, const TArray<AHealers_CharacterSheet*>& targets)
{
	SpellLifespan = SpellDuration;

	BP_ExecuteSpell(spellOwner, caster, targets);
}

void UHealers_SpellComponent::TickSpell(float deltaSec)
{
	if (SpellLifespan > 0.f)
	{
		SpellLifespan -= deltaSec;
		BP_TickSpell(deltaSec);

		if (SpellLifespan <= 0.f)
		{
			ShutdownSpell();
		}
	}
}

void UHealers_SpellComponent::ShutdownSpell()
{
	BP_ShutdownSpell();
}

void UHealers_SpellComponent::DestroySpellComponent()
{
	BP_DestroySpellComponent();
}

bool UHealers_SpellComponent::IsSpellActive() const
{
	return (SpellLifespan > 0.f);
}

void UHealers_SpellComponent::BP_ExecuteSpell_Implementation(AHealers_Spell* spellOwner, AHealers_CharacterSheet* caster, const TArray<AHealers_CharacterSheet*>& targets)
{
	//Noop
}

void UHealers_SpellComponent::BP_TickSpell_Implementation(float deltaSec)
{
	//Noop
}

void UHealers_SpellComponent::BP_ShutdownSpell_Implementation()
{
	//Noop
}

void UHealers_SpellComponent::BP_DestroySpellComponent_Implementation()
{
	//Noop
}