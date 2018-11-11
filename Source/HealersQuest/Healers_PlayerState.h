// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "Healers_QuestContract.h"

#include "Healers_PlayerState.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

struct FHealers_QuestContract;
class AHealers_PartySheet;

/////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_PlayerState : public APlayerState
{
    GENERATED_BODY()
    
    AHealers_PlayerState();

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerState")
    int32 Gold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerState")
    int32 Reputation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerState")
    FQuestContract QuestContract;

    UFUNCTION(BlueprintPure, meta = (Keywords = "Character Sheet"), Category = "PlayerState")
    AHealers_CharacterSheet* GetHealersCharacterSheet() const;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Keywords = "Party Sheet"), Category = "PlayerState")
    AHealers_PartySheet* PartySheet;
    
};
