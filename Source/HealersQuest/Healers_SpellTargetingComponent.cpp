// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_SpellTargetingComponent.h"

UHealers_SpellTargetingComponent::UHealers_SpellTargetingComponent(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{

}

TArray<AActor*> UHealers_SpellTargetingComponent::GetTargets (APawn* caster) const
{
	return TArray<AActor*>(); //Return empty list
}