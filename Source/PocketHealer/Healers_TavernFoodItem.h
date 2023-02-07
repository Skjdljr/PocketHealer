// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Info.h"

#include "HealersQuest.h"

#include "Healers_TavernFoodItem.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * FTavernFoodItem : Structure defining FoodItem.
 */
USTRUCT(Blueprintable)
struct POCKETHEALER_API FTavernFoodItem : public FTableRowBase
{
    GENERATED_BODY()
    
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    FString ItemName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    FString Description;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    UTexture2D* Image;

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    //FQuestContractPrerequisite Prerequisite;

    // Cost in Gold. (Should there ever be costs in other types?)
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestContract")
    int32 Cost;
    
};

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/**
* AHealers_TavernFoodItem : Tavern Food Item Actor. Run-time instance of a FoodItem.
*
*/
UCLASS(Blueprintable, BlueprintType, NotPlaceable)
class POCKETHEALER_API AHealers_TavernFoodItem : public AInfo
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "FoodItem")
    FTavernFoodItem FoodItem;
};