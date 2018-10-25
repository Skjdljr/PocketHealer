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
            //noop
            break;
        }
    }
}

void AHealers_BattleCoordinator::AddInitiative(float dt, TArray<AHealers_CharacterSheet*> sheet, bool isEnemy)
{
    auto target = isEnemy ? GetRandomPartyTarget() : GetRandomEnemyTarget();

    for (auto member : sheet)
    {
        member->SetInitiative(member->GetInitiativePerSecond() * dt);
        
        if (member->GetInitiative() > MAX_INITIATIVE)
        {
            if (target != nullptr)
            {
                member->SetInitiative(0);
                
                UE_LOG(Game, Log, TEXT("Character attacked - "));
                Take_Damage(target, member);
            }
            else
            {
                UE_LOG(Game, Log, TEXT("You dun goofed, target is null"));
            }
        }
    }
}

void AHealers_BattleCoordinator::TickAllCharacters(float dt)
{
    //Need a better name, this also does dmg.... Confusing I know leave me alone
    AddInitiative(dt, BattleData.EnemyMembers, true);
    AddInitiative(dt, BattleData.PartyMembers, false);
}

void AHealers_BattleCoordinator::Take_Damage(AHealers_CharacterSheet* defender, AHealers_CharacterSheet* attacker)
{
    //TODO? maybe overload aactors TakeDamage for now use our own
    //TODO? Maybe overload aactors ReceiveAnyDamage?
    
    if (defender != nullptr && attacker != nullptr)
    {
        //TODO: actually write the CalculateDamage function
        auto newHealth = CalculateDamage(defender->GetCharacterAttributes(), attacker->GetCharacterAttributes());

        UE_LOG(Game, Log, TEXT("newHealth = %d"), newHealth);

        if (newHealth >= 0)
            defender->SetHealth(newHealth);
        else
        {
            defender->SetHealth(0);
            UE_LOG(Game, Log, TEXT("Health or Attacker null!"));

            //Remove them from the list?
        }
    }
    else
    {
        UE_LOG(Game, Log, TEXT("Defender or Attacker null!"));
    }
}

float AHealers_BattleCoordinator::CalculateDamage(FCharacterAttributes& defender, FCharacterAttributes& attacker)
{
    //TODO: -Calculate this based of armor/resistances/attackspeed/crit what ever else
    //for now just do health - dmg... bc gamejam
    return defender.Health - attacker.AttackPower;
}

AHealers_CharacterSheet* AHealers_BattleCoordinator::GetRandomEnemyTarget()
{
    AHealers_CharacterSheet* target = nullptr;

    if (!IsPartyDefeated() && !IsEnemyDefeated())
    {
        auto index = FMath::FRandRange(0, BattleData.EnemyMembers.Num() - 1);
        target = BattleData.EnemyMembers[index];
        //need to check the target isn't defeated.... or just remove the defeated ones from the array...
    }

    return target;
}

AHealers_CharacterSheet * AHealers_BattleCoordinator::GetRandomPartyTarget()
{
    AHealers_CharacterSheet* target = nullptr;

    if (!IsPartyDefeated() && !IsEnemyDefeated())
    {
        auto index = FMath::FRandRange(0, BattleData.PartyMembers.Num() - 1);
        target = BattleData.PartyMembers[index];
        //need to check the target isn't defeated.... or just remove the defeated ones from the array...
    }

    return target;
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
