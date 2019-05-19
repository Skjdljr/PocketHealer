// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_SpellComponent.h"
#include "Healers_CharacterSheet.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

void UHealers_SpellComponent::ExecuteSpell(AHealers_Spell* SpellOwner, AHealers_CharacterSheet* caster, const TArray<AHealers_CharacterSheet*>& Targets)
{
	SpellLifespan = SpellDuration;

	BP_ExecuteSpell(SpellOwner, caster, Targets);
}

void UHealers_SpellComponent::TickSpell(float DeltaSec)
{
	if (SpellLifespan > 0.f)
	{
		SpellLifespan -= DeltaSec;
		BP_TickSpell(DeltaSec);

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

void UHealers_SpellComponent::BP_ExecuteSpell_Implementation(AHealers_Spell* SpellOwner, AHealers_CharacterSheet* caster, const TArray<AHealers_CharacterSheet*>& Targets)
{
	//Noop
}

void UHealers_SpellComponent::BP_TickSpell_Implementation(float DeltaSec)
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