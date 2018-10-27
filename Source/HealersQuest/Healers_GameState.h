// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"

#include "Healers_QuestContract.h"

#include "Healers_GameState.generated.h"


/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

struct FHealers_QuestContract;

/////////////////////////////////////////////////////////////////////////////////////////////////
// Delegates

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMatchStateChanged);

/////////////////////////////////////////////////////////////////////////////////////////////////

UENUM()
enum EAdventureState
{
    AS_Tavern,
    AS_Battle,
    AS_MAX
};

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_GameState : public AGameState
{
    GENERATED_BODY()

public:

    virtual void OnRep_MatchState() override;

    UPROPERTY(BlueprintAssignable)
    FMatchStateChanged OnMatchStateChanged;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameState")
    int32 Gold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameState")
    int32 Reputation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameState")
    FHealers_QuestContract ActiveQuestContract;

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameState")

};
