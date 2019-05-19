// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_Spell.h"

#include "Kismet/GameplayStatics.h"

#include "Healers_CharacterSheet.h"
#include "Healers_SpellComponent.h"
#include "Healers_SpellPrerequisiteComponent.h"
#include "Healers_SpellTargetingComponent.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

AHealers_Spell::AHealers_Spell(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{
    PrimaryActorTick.bCanEverTick = true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void AHealers_Spell::BeginPlay()
{
    Super::BeginPlay();

    GetComponents(OUT SpellComponents);
    GetComponents(OUT Prerequisites);

    TargetComponent = FindComponentByClass<UHealers_SpellTargetingComponent>();
}

void AHealers_Spell::Destroyed()
{
    for (auto& CurrentComponent : SpellComponents)
    {
        CurrentComponent->DestroySpellComponent();
    }

    Super::Destroyed();
}

void AHealers_Spell::Tick(float DeltaSec)
{
    Super::Tick(DeltaSec);

    for (auto& CurrentPrerequisite : Prerequisites)
    {
        CurrentPrerequisite->TickPrerequisite(DeltaSec);
    }

    for (auto& CurrentComponent : SpellComponents)
    {
        CurrentComponent->TickSpell(DeltaSec);
    }
}

bool AHealers_Spell::CanCastSpell(AHealers_CharacterSheet* Caster) const
{
    for (auto& CurrentPrerequisite : Prerequisites)
    {
        if (!CurrentPrerequisite->CanCastSpell(Caster))
        {
            return false;
        }
    }

    //Can't cast it again if it's already active
    for (auto& CurrentComponent : SpellComponents)
    {
        if (CurrentComponent->IsSpellActive())
        {
            return false;
        }
    }

    return true;
}

bool AHealers_Spell::CanCastSpellOnTargets(AHealers_CharacterSheet* Caster, const TArray<AHealers_CharacterSheet*>& Targets) const
{
    for (auto& CurrentPrerequisite : Prerequisites)
    {
        if (!CurrentPrerequisite->CanCastSpellOnTargets(Caster, Targets))
        {
            return false;
        }
    }

    return true;
}

void AHealers_Spell::CastSpell(AHealers_CharacterSheet* Caster, const TArray<AHealers_CharacterSheet*>& Targets)
{
    //UGameplayStatics::PlaySound2D(caster, SpellCastSound);

    for (auto& CurrentPrerequisite : Prerequisites)
    {
        CurrentPrerequisite->SpellExecuted(Caster);
    }

    for (auto& CurrentComponent : SpellComponents)
    {
        CurrentComponent->ExecuteSpell(this, Caster, Targets);
    }
}