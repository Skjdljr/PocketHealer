#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Info.h"

#include "HealersQuest.h"
#include "Healers_CharacterSheet.h"

#include "Healers_QuestContract.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

class AHealers_CharacterSheet;

/////////////////////////////////////////////////////////////////////////////////////////////////

USTRUCT(BlueprintType, Blueprintable)
struct HEALERSQUEST_API FAdventureBattle
{
    GENERATED_BODY();

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Battle Data")
    TArray<FCharacterSheet> PartyMembers;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Battle Data")
    TArray<FCharacterSheet> EnemyMembers;

    //TODO:
    //Add some representation of waves/level
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Battle Data")
    USoundBase* SoundBattle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Battle Data")
    USoundBase* SoundVictory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Battle Data")
    USoundBase* SoundDefeat;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

USTRUCT(Blueprintable)
struct HEALERSQUEST_API FAdventureStep
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Adveture Step")
    UTexture2D* Background;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Adveture Step")
    FAdventureBattle Battle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Adveture Step")
    FString StringEnter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Adveture Step")
    FString StringExit;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

USTRUCT(Blueprintable)
struct HEALERSQUEST_API FQuestContractPrerequisite : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract Prerequisite")
    int32 Level;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract Prerequisite")
    ECharacterProfession Profession;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract Prerequisite")
    int32 Reputation;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

USTRUCT(Blueprintable)
struct HEALERSQUEST_API FQuestContractReward
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract Reward")
    int32 Gold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract Reward")
    int32 Reputation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract Reward")
    int32 Experience;

    // TODO : Inventory Item Rewards

    // TODO : Skill or Stat buffs.
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 
 */
USTRUCT(Blueprintable)
struct HEALERSQUEST_API FQuestContract : public FTableRowBase
{
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    int32 ID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    FString ContractName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    FString Description;
    
    // @! TODO Figure out how to reference from CharacterLibrary
    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    //FString ContactName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    UTexture2D* Image;

    // Gold cost. Might be dumb but it's the only use we have for gold currently
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    int32 Cost;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    FQuestContractPrerequisite Prerequisite;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    FQuestContractReward Reward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    float ChallengeRating;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    TArray<FAdventureStep> Steps;


    // Time cost

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    //TArray<AHealers_CharacterSheet*> ContractMembers;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
* AHealers_QuestContract : Quest Contract Actor. Run-time instance of a QuestContract.
*
*/
UCLASS(Blueprintable, BlueprintType, NotPlaceable)
class HEALERSQUEST_API AHealers_QuestContract : public AInfo
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    FQuestContract QuestContract;
};
