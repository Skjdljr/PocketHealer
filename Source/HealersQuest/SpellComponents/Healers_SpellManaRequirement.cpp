// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_SpellManaRequirement.h"
#include "Healers_CharacterSheet.h"

UHealers_SpellManaRequirement::UHealers_SpellManaRequirement(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{

}

bool UHealers_SpellManaRequirement::CanCastSpell(AHealers_CharacterSheet* caster) const
{
    if (!Super::CanCastSpell(caster))
    {
        return false;
    }


    // @! TODO FIX
    return (caster == nullptr || caster->GetMana() >= ManaCost);
   
}

void UHealers_SpellManaRequirement::SpellExecuted(AHealers_CharacterSheet* caster)
{
    Super::SpellExecuted(caster);

    if (caster != nullptr)
    {
        auto Mana = caster->GetMana();
        Mana -= ManaCost;
        caster->SetMana(Mana);
    }
}