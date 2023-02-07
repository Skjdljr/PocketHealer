// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_SpellBar.h"

#include "Healers_Spell.h"
#include "Healers_CharacterSheet.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

AHealers_SpellBar::AHealers_SpellBar() :
    Caster(nullptr),
    SelectedSpell(nullptr)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////

bool AHealers_SpellBar::SelectSpell(int32 Index)
{
    if (SpellBar.Num() > Index)
    {
        AHealers_Spell* CurrentSpell = SpellBar[Index];

        if (CurrentSpell->CanCastSpell(Caster))
        {
            // TODO : If TargetComponent == SingleTarget || MultiTargetComponent
            if (CurrentSpell->TargetComponent)
            {
            }
            // TODO else if AutoTarget, SelfTarget, GlobalTarget... Try to Cast
            else
            {
                SelectedSpell = CurrentSpell;

                const TArray<AHealers_CharacterSheet*> Targets = TArray<AHealers_CharacterSheet*>();
                SelectedSpell->CastSpell(nullptr, Targets);
            }
        }
    }

    return SelectedSpell;
}