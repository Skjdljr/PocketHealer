// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_SpellBar.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

AHealers_SpellBar::AHealers_SpellBar() :
    Caster(nullptr)
    //SelectedSpell(nullptr)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////

bool AHealers_SpellBar::SelectSpell(int32 Index)
{
    //AHealers_Spell* CasterSpell;

    //if (SpellBar.Num() > Index)
    {
        //AHealers_Spell* CurrentSpell = SpellBar[Index];

        //if (spell->CanCastSpell(CasterSpell))
        {
            // TODO : If TargetComponent == SingleTarget || MultiTargetComponent
            // TODO else if AutoTarget, SelfTarget, GlobalTarget... Try to Cast
            {
                //SelectedSpell = spell;

                //const TArray<AHealers_CharacterSheet*> Targets = TArray<AHealers_CharacterSheet*>();
                //SelectedSpell->CastSpell(nullptr, Targets);
            }
        }
    }

    return false;
}