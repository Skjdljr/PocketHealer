// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Healers_GameMode.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

class UDataTable;
class AHealers_BattleCoordinator;

/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_GameMode : public AGameMode
{
    GENERATED_BODY()

public:

    AHealers_GameMode();

    // Override BeginPlay()
    virtual void BeginPlay() override;
    virtual void StartMatch() override;

    UFUNCTION(BlueprintCallable, Category = "GameMode")
    void BP_StartMatch();

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GameMode")
    UDataTable* CharacterRaceLibrary;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GameMode")
    UDataTable* CharacterProfessionLibrary;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GameMode")
    UDataTable* CharacterProfessionIconSetLibrary;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GameMode")
    UDataTable* CharacterAllyLibrary;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GameMode")
    UDataTable* CharacterEnemyLibrary;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GameMode")
    UDataTable* QuestContractLibrary;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GameMode")
    UDataTable* QuestBattleLibrary;

    UPROPERTY(Config = Game, BlueprintReadWrite, EditDefaultsOnly, Category = "GameMode")
    int32 DefaultStartingGold;

    UPROPERTY(Config = Game, BlueprintReadWrite, EditDefaultsOnly, Category = "GameMode")
    int32 DefaultStartingReputation;
    
    UPROPERTY(BlueprintReadWrite, Category = "GameMode")
    AHealers_BattleCoordinator* BattleCoordinator;
};
