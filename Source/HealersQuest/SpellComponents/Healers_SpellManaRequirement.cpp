// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_SpellManaRequirement.h"
#include "Healers_CharacterSheet.h"

UHealers_SpellManaRequirement::UHealers_SpellManaRequirement(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{

}

bool UHealers_SpellManaRequirement::CanCastSpell(APawn* caster) const
{
    if (!Super::CanCastSpell(caster))
    {
        return false;
    }

    AHealers_CharacterSheet* charSheet = AHealers_CharacterSheet::GetCharacterSheet(caster);

    // @! TODO FIX
    //return (charSheet == nullptr || charSheet->Mana >= ManaCost);
    return false;
}

void UHealers_SpellManaRequirement::SpellExecuted(APawn* caster)
{
    Super::SpellExecuted(caster);

    AHealers_CharacterSheet* charSheet = AHealers_CharacterSheet::GetCharacterSheet(caster);
    if (charSheet != nullptr)
    {
        auto Mana = charSheet->GetMana();
        Mana -= ManaCost;
        charSheet->SetMana(Mana);
    }
}