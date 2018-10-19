
#pragma once

#include "CoreMinimal.h"
#include "Actor.h"
#include "Healers_BattleCoordinator.generated.h"

class AHealers_CharacterSheet;

USTRUCT()
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
class HEALERSQUEST_API AHealers_BattleCoordinator  : public AActor
{
    GENERATED_BODY()

    FBattleData BattleData;

    EBattleState BattleState;

    AHealers_BattleCoordinator();

    //Inherited 
    virtual void BeginPlay() override;

    virtual void Tick(float dt) override;

    UFUNCTION()
    bool IsPartyDefeated();

    UFUNCTION()
    bool IsEnemyDefeated();

    //Ours
    void SetBattleState(EBattleState newState);

    //todo: duration?
};