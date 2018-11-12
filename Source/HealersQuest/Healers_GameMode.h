// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Healers_GameMode.generated.h"

class UDataTable;

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_GameMode : public AGameMode
{
    GENERATED_BODY()

public:

    AHealers_GameMode();

    // Reference UMG Asset in the Editor
    UPROPERTY(BlueprintReadOnly, Category = "GameMode")
    UUserWidget* MainMenu;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
    TSubclassOf<class UUserWidget> MainMenuClass;

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

};
