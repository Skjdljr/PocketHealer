// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_SpellPrerequisiteComponent.h"
#include "Healers_CharacterSheet.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

UHealers_SpellPrerequisiteComponent::UHealers_SpellPrerequisiteComponent(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////

bool UHealers_SpellPrerequisiteComponent::CanCastSpell(AHealers_CharacterSheet* Caster) const
{
	return true;
}

bool UHealers_SpellPrerequisiteComponent::CanCastSpellOnTargets(AHealers_CharacterSheet* Caster, const TArray<AHealers_CharacterSheet*>& Targets) const
{
	return true;
}

void UHealers_SpellPrerequisiteComponent::SpellExecuted(AHealers_CharacterSheet* Caster)
{
	//Noop
}

void UHealers_SpellPrerequisiteComponent::TickPrerequisite (float DeltaSec)
{
	//Noop
}