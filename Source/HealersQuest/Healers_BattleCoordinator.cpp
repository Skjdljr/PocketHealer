#include "Healers_BattleCoordinator.h"

AHealers_BattleCoordinator::AHealers_BattleCoordinator()
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
            if (/*IsBattleReadyToStart()*/)
            {
                SetBattleState(BS_BATTLE_IN_PROGRESS);
                //OnBattleBeginDelegate
            }
            break;
        }
        case BS_BATTLE_IN_PROGRESS:
        {
            //TickAllCharacters(); // or just Enable Tick on all characters(?)

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
            if (/*IsBattleComplete()*/)
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

bool AHealers_BattleCoordinator::IsPartyDefeated()
{
    bool isPartyDefeated = true;

    //for (auto member : BattleData.PartyMembers)
    //{
    //    if (member.data.data > 0)
    //    {
    //        isPartyDefeated = false;
    //    }
    //}

    return isPartyDefeated;
}

bool AHealers_BattleCoordinator::IsEnemyDefeated()
{
    bool isPartyDefeated = true;

   /* for (auto member : BattleData.EnemyMembers)
    {
        if (member.data.data.health > 0)
        {
            isPartyDefeated = false;
        }
    }*/

    return isPartyDefeated;
}

void AHealers_BattleCoordinator::SetBattleState(EBattleState newState)
{
    if (newState != BattleState)
    {
        BattleState = newState;
    }
}
