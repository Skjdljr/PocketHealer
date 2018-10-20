// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_DamageModifier.h"

UHealers_DamageModifier::UHealers_DamageModifier(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UHealers_DamageModifier::ExecuteSpell(AHealers_Spell* spellOwner, APawn* caster, const TArray<AActor*>& targets)
{
    Super::ExecuteSpell(spellOwner, caster, targets);

    for (int i = 0; i < targets.Num(); ++i)
    {
        GiveDamageModifierToTarget(targets[i]);
    }
}

void UHealers_DamageModifier::ShutdownSpell ()
{
    RemoveDamageModifiers();

    Super::ShutdownSpell();
}

void UHealers_DamageModifier::DestroySpellComponent ()
{
    RemoveDamageModifiers();

    Super::DestroySpellComponent();
}

void UHealers_DamageModifier::GiveDamageModifierToTarget (AActor* newTarget)
{
    APawn* p = Cast<APawn>(newTarget);
    if (p != nullptr)
    {
        AHealers_CharacterSheet* characterSheet = AHealers_CharacterSheet::GetCharacterSheet(p);
        if (characterSheet != nullptr)
        {
            Targets.Add(characterSheet);

            for (int dmgIdx = 0; dmgIdx < DamageModifiers.Num(); ++dmgIdx)
            {
                // TODO : Use a Getter in the CharacterSheet instead of directly accessing these values
                for (int charIdx = 0; charIdx < characterSheet->CharacterSheet.Attributes.Resistances.Num(); ++charIdx)
                {
                    if (characterSheet->CharacterSheet.Attributes.Resistances[charIdx].DamageType == DamageModifiers[dmgIdx].DamageType)
                    {
                        characterSheet->CharacterSheet.Attributes.Resistances[charIdx].DamageResistanceValue += DamageModifiers[dmgIdx].DamageResistanceValue;
                        break;
                    }
                }
            }
        }
    }
}

void UHealers_DamageModifier::RemoveDamageModifiers ()
{
    for (int targetIdx = 0; targetIdx < Targets.Num(); ++targetIdx)
    {
        for (int dmgIdx = 0; dmgIdx < DamageModifiers.Num(); ++dmgIdx)
        {
            // TODO : Use a Getter in the CharacterSheet instead of directly accessing these values
            for (int charIdx = 0; charIdx < Targets[targetIdx]->CharacterSheet.Attributes.Resistances.Num(); ++charIdx)
            {
                if (Targets[targetIdx]->CharacterSheet.Attributes.Resistances[charIdx].DamageType == DamageModifiers[dmgIdx].DamageType)
                {
                    //Undo the damage modifier
                    Targets[targetIdx]->CharacterSheet.Attributes.Resistances[charIdx].DamageResistanceValue -= DamageModifiers[dmgIdx].DamageResistanceValue;
                    break; //Go to next DamageModifier
                }
            }
        }
    }

    Targets.Empty();
}