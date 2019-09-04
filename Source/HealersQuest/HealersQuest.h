// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Net/UnrealNetwork.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

DECLARE_LOG_CATEGORY_EXTERN(Game, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(GameUI, Log, All);

/////////////////////////////////////////////////////////////////////////////////////////////////

UENUM(BlueprintType)
enum class ECharacterRace : uint8
{
    RACE_Null		UMETA(Hidden),
    RACE_Human		UMETA(DisplayName = "Human"),
    RACE_Elf		UMETA(DisplayName = "Elf"),
    RACE_Dwarf		UMETA(DisplayName = "Dwarf"),
    RACE_Orc		UMETA(DisplayName = "Orc"),
    RACE_Monster	UMETA(DisplayName = "Monster"),
    RACE_Beast		UMETA(DisplayName = "Beast"),
    RACE_Plant		UMETA(DisplayName = "Plant"),
    RACE_Dragon		UMETA(DisplayName = "Dragon"),
    RACE_Undead		UMETA(DisplayName = "Undead"),
    RACE_Elemental	UMETA(DisplayName = "Elemental"),
    RACE_Construct	UMETA(DisplayName = "Construct"),
    RACE_Max		UMETA(Hidden),
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

UENUM(BlueprintType)
enum class ECharacterProfession : uint8
{
    PROFESSION_Null			UMETA(Hidden),
    PROFESSION_Commoner		UMETA(DisplayName = "Commoner"),
    PROFESSION_Healer		UMETA(DisplayName = "Healer"),
    PROFESSION_Sage			UMETA(DisplayName = "Sage"),
    PROFESSION_Druid		UMETA(DisplayName = "Druid"),
    PROFESSION_Defender		UMETA(DisplayName = "Defender"),
    PROFESSION_Barbarian	UMETA(DisplayName = "Barbarian"),
    PROFESSION_Knight		UMETA(DisplayName = "Knight"),
    PROFESSION_Rogue		UMETA(DisplayName = "Rogue"),
    PROFESSION_Ranger		UMETA(DisplayName = "Ranger"),
    PROFESSION_Wizard		UMETA(DisplayName = "Wizard"),
    PROFESSION_Max			UMETA(Hidden),
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

UENUM(BlueprintType)
enum class EDamageResistance : uint8
{
    DR_Null			UMETA(Hidden),
    DR_Physical		UMETA(DisplayName = "Physical"),
    DR_Fire			UMETA(DisplayName = "Fire"),
    DR_Cold			UMETA(DisplayName = "Cold"),
    DR_Lightning	UMETA(DisplayName = "Lightning"),
    DR_Poison		UMETA(DisplayName = "Poison"),
    DR_Psychic		UMETA(DisplayName = "Psychic"),
    DR_Magic		UMETA(DisplayName = "Magic"),
    DR_Death		UMETA(DisplayName = "Death"),
    DR_Holy			UMETA(DisplayName = "Holy"),
    DR_Max			UMETA(Hidden),
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////