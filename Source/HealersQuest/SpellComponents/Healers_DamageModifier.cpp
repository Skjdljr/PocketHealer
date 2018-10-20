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
                // Get reference to Resistances
                auto& Resistances = characterSheet->GetResistances();
                for (int charIdx = 0; charIdx < Resistances.Num(); ++charIdx)
                {
                    if (Resistances[charIdx].DamageType == DamageModifiers[dmgIdx].DamageType)
                    {
                        Resistances[charIdx].DamageResistanceValue += DamageModifiers[dmgIdx].DamageResistanceValue;
                        Resistances[charIdx].DamageResistancePercentValue += DamageModifiers[dmgIdx].DamageResistancePercentValue;
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
            // Get reference to Resistances
            auto& Resistances = Targets[targetIdx]->GetResistances();
            for (int charIdx = 0; charIdx < Resistances.Num(); ++charIdx)
            {
                if (Resistances[charIdx].DamageType == DamageModifiers[dmgIdx].DamageType)
                {
                    //Undo the damage modifier
                    Resistances[charIdx].DamageResistanceValue -= DamageModifiers[dmgIdx].DamageResistanceValue;
                    Resistances[charIdx].DamageResistancePercentValue -= DamageModifiers[dmgIdx].DamageResistancePercentValue;
                    break; //Go to next DamageModifier
                }
            }
        }
    }

    Targets.Empty();
}