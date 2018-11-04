// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Healers_PlayerState.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

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

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|Party")
    int32 Gold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|Party")
    int32 Reputation;

    UFUNCTION(BlueprintPure, meta = (Keywords = "Character Sheet"), Category = "CharacterSheet")
    AHealers_CharacterSheet* GetHealersCharacterSheet() const;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Keywords = "Party Sheet"), Category = "Healers|Party")
    AHealers_PartySheet* PartySheet;
    
};
