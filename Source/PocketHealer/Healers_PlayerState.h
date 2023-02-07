// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "Healers_QuestContract.h"

#include "Healers_PlayerState.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

struct FHealers_QuestContract;

/////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * 
 */
UCLASS()
class POCKETHEALER_API AHealers_PlayerState : public APlayerState
{
    GENERATED_BODY()
    
    AHealers_PlayerState();

public:

    virtual void BeginPlay() override;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerState")
    int32 Gold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerState")
    int32 Reputation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "PlayerState")
    FQuestContract QuestContract;

    //TODO: add a getter for what ever we are using ot replace CharacterSheet and PartySheet
    
};
