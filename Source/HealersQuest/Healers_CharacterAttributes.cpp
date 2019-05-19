// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_CharacterAttributes.h"

#include "HealersQuest.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region StructDamageResistance

FDamageResistance::FDamageResistance() :
    DamageType(EDamageResistance::DR_Null),
    DamageResistancePercentValue(0.0f),
    DamageResistanceValue(0.0f)
{
}

#pragma endregion StructDamageResistance

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma region FCharacterAttributes

FCharacterAttributes::FCharacterAttributes() :
    Health(0.f),
    HealthMax(0.f),
    Mana(0.f),
    ManaMax(0.f),
    ManaRegenerationPerSecond(0.f),
    Initiative(0.f),
    InitiativePerSecond(0.f),
    AttackAccuracy(0.f),
    AttackPower(0.f),
    MagicAccuracy(0.f),
    MagicPower(0.f),
    CriticalDamageChance(0.f),
    CriticalDamageValue(0.f),
    EvasionValue(0.f),
    ArmorValue(0.f),
    LuckValue(0.f)
{
}

#pragma endregion FCharacterAttributes