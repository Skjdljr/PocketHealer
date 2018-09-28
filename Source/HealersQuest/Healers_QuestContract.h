

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Healers_QuestContract.generated.h"

class AHealers_CharacterSheet;

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_QuestContract : public AInfo
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "QuestContract")
	int32 ID;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "QuestContract")
	FString ContractDescription;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "QuestContract")
	FString ContractOwnerName;

	UTexture2D* ContractImage;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "QuestContract")
	int32 ChallengeRating;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "QuestContract")
	TArray<AHealers_CharacterSheet*> ContractMembers;


	//TArray<AdventureSteps>

	//FContractReward Reward;
};
