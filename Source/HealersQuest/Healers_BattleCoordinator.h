
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Healers_BattleCoordinator.generated.h"

class AHealers_CharacterSheet;

USTRUCT(Blueprintable)
struct FBattleData
{
    GENERATED_BODY();

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Battle Data")
        TArray<AHealers_CharacterSheet*> PartyMembers;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Battle Data")
        TArray<AHealers_CharacterSheet*> EnemyMembers;

    //TODO:
    //Add some representation of waves/level
};

UENUM()
enum EBattleState
{
    BS_PRE_BATTLE = 0,
    BS_BATTLE_IN_PROGRESS,
    BS_POST_BATTLE,
    BS_BATTLE_COMPLETE
};

UCLASS()
class HEALERSQUEST_API AHealers_BattleCoordinator : public AActor
{
    GENERATED_BODY()

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Battle Data")
    FBattleData BattleData;

    //UPROPERTY()
    EBattleState BattleState;

    UPROPERTY(/*BlueprintReadWrite,*/ EditAnywhere, Category = "Battle Data")
    bool bIsBattleComplete;

    UPROPERTY(/*BlueprintReadWrite,*/ EditAnywhere, Category = "Battle Data")
    bool bIsBattleReadyToStart;

    UPROPERTY(/*BlueprintReadWrite,*/ EditAnywhere, Category = "Battle Data")
    int MAX_INITIATIVE = 100;

    AHealers_BattleCoordinator();

    //Inherited 
    virtual void BeginPlay() override;

    virtual void Tick(float dt) override;

    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Battle Data")
    bool IsPartyDefeated();

    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Battle Data")
    bool IsEnemyDefeated();

    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Battle Data")
    bool IsBattleComplete();

    UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Battle Data")
    bool IsBattleReadyToStart();

    //Ours
    void SetBattleState(EBattleState newState);

    void TickAllCharacters(float dt);
    
    AHealers_CharacterSheet* GetRandomTarget();

    //todo: duration?
};