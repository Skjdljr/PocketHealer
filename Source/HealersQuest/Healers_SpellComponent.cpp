// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_SpellComponent.h"

UHealers_SpellComponent::UHealers_SpellComponent(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{

}

void UHealers_SpellComponent::ExecuteSpell (AHealers_Spell* spellOwner, APawn* caster, const TArray<AActor*>& targets)
{
	SpellLifespan = SpellDuration;

	BP_ExecuteSpell(spellOwner, caster, targets);
}

void UHealers_SpellComponent::TickSpell (float deltaSec)
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

void UHealers_SpellComponent::ShutdownSpell ()
{
	BP_ShutdownSpell();
}

void UHealers_SpellComponent::DestroySpellComponent ()
{
	BP_DestroySpellComponent();
}

bool UHealers_SpellComponent::IsSpellActive () const
{
	return (SpellLifespan > 0.f);
}

void UHealers_SpellComponent::BP_ExecuteSpell_Implementation (AHealers_Spell* spellOwner, APawn* caster, const TArray<AActor*>& targets)
{
	//Noop
}

void UHealers_SpellComponent::BP_TickSpell_Implementation (float deltaSec)
{
	//Noop
}

void UHealers_SpellComponent::BP_ShutdownSpell_Implementation ()
{
	//Noop
}

void UHealers_SpellComponent::BP_DestroySpellComponent_Implementation ()
{
	//Noop
}