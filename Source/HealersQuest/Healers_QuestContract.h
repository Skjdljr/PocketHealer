

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Info.h"
#include "Healers_QuestContract.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

class AHealers_CharacterSheet;

/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 
 */
USTRUCT(Blueprintable)
struct HEALERSQUEST_API FHealers_QuestContract : public FTableRowBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
	int32 ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
	FString ContractDescription;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
	FString ContractOwnerName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
	UTexture2D* ContractImage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
	int32 ChallengeRating;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
	TArray<AHealers_CharacterSheet*> ContractMembers;


	//TArray<AdventureSteps>

	//FContractReward Reward;
};
