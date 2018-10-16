// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_SpellPrerequisiteComponent.h"

UHealers_SpellPrerequisiteComponent::UHealers_SpellPrerequisiteComponent(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{

}

bool UHealers_SpellPrerequisiteComponent::CanCastSpell(APawn* caster) const
{
	return true;
}

bool UHealers_SpellPrerequisiteComponent::CanCastSpellOnTargets(APawn* caster, const TArray<AActor*>& targets) const
{
	return true;
}

void UHealers_SpellPrerequisiteComponent::SpellExecuted(APawn* caster)
{
	//Noop
}

void UHealers_SpellPrerequisiteComponent::TickPrerequisite (float deltaSec)
{
	//Noop
}