// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_SpellManaRequirement.h"
#include "Healers_CharacterSheet.h"

UHealers_SpellManaRequirement::UHealers_SpellManaRequirement(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{

}

bool UHealers_SpellManaRequirement::CanCastSpell(AHealers_CharacterSheet* caster) const
{
    bool IsAbleToCast = false;
    if (!Super::CanCastSpell(caster))
    {
        IsAbleToCast = false;
    }
    else if (caster != nullptr)
    {
        IsAbleToCast = caster->GetMana() >= ManaCost;
    }

    return IsAbleToCast;
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