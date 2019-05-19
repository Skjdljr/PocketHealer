// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_SpellTargetingComponent.h"
#include "Healers_CharacterSheet.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

UHealers_SpellTargetingComponent::UHealers_SpellTargetingComponent(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{

}

/////////////////////////////////////////////////////////////////////////////////////////////////

TArray<AHealers_CharacterSheet*> UHealers_SpellTargetingComponent::GetTargets (AHealers_CharacterSheet* caster) const
{
	return TArray<AHealers_CharacterSheet*>(); //Return empty list
}