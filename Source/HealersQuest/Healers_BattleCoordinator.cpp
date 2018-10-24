#include "Healers_BattleCoordinator.h"
#include "Healers_CharacterSheet.h"

AHealers_BattleCoordinator::AHealers_BattleCoordinator(): bIsBattleComplete(false), bIsBattleReadyToStart(true)
{

    PrimaryActorTick.bCanEverTick = true;
}

void AHealers_BattleCoordinator::BeginPlay()
{

}

void AHealers_BattleCoordinator::Tick(float dt)
{

    switch (BattleState)
    {
    case BS_PRE_BATTLE:
    {
        if (IsBattleReadyToStart())
        {
            SetBattleState(BS_BATTLE_IN_PROGRESS);
            //OnBattleBeginDelegate
        }
        break;
    }
    case BS_BATTLE_IN_PROGRESS:
    {
        TickAllCharacters(dt); 
            
        // Victory or Defeat Conditions
        if (IsPartyDefeated() || IsEnemyDefeated())
        {
            SetBattleState(BS_POST_BATTLE);
            //OnBattleEndedDelegate
        }

        //

        break;
    }
    case BS_POST_BATTLE:
    {
        //
        if (IsBattleComplete())
        {
            SetBattleState(BS_BATTLE_COMPLETE);
            //OnBattleCompleted
        }

        break;
    }

    default:
    {
        break;
    }
    //noop
    }

}

void AHealers_BattleCoordinator::TickAllCharacters(float dt)
{
    for (auto member : BattleData.PartyMembers)
    {
        member->SetInitiative(member->GetInitiativePerSecond() * dt);

        if (member->GetInitiative() > MAX_INITIATIVE)
        {
            //member.DoAction();
        }
    }
    //for each character update initiative based on charactersheet init.
                //once we reach threshhold of 100 do action
                    //Action will be a selection of (1) ability from char sheet
                    //need to be able to select target with function below
       //GetRandomTarget( pass in self)
        //fire spell
}

AHealers_CharacterSheet* AHealers_BattleCoordinator::GetRandomTarget()
{
    return nullptr;
}

bool AHealers_BattleCoordinator::IsPartyDefeated()
{
    bool isPartyDefeated = true;

    for (auto member : BattleData.PartyMembers)
    {
        if (member->GetHealth() > 0)
        {
            isPartyDefeated = false;
        }
    }

    return isPartyDefeated;
}

bool AHealers_BattleCoordinator::IsEnemyDefeated()
{
    bool isPartyDefeated = true;

    for (auto member : BattleData.EnemyMembers)
    {
        if (member->GetHealth() > 0)
        {
            isPartyDefeated = false;
        }
    }

    return isPartyDefeated;
}

bool AHealers_BattleCoordinator::IsBattleComplete()
{
    //todo create logic and have it set bIsBattleComplete
    return bIsBattleComplete;
}

bool AHealers_BattleCoordinator::IsBattleReadyToStart()
{
    //todo create logic and have it set bIsBattleReadyToStart

    return bIsBattleReadyToStart;
}

void AHealers_BattleCoordinator::SetBattleState(EBattleState newState)
{
    if (newState != BattleState)
    {
        BattleState = newState;
    }
}
