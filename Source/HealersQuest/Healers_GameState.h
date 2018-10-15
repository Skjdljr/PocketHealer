// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "Healers_GameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMatchStateChanged);

class AHealers_QuestContract;

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_GameState : public AGameState
{
	GENERATED_BODY()

public:

	virtual void OnRep_MatchState() override;

	UPROPERTY(BlueprintAssignable)
	FMatchStateChanged OnMatchStateChanged;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "GameState")
	//TArray<AHealers_QuestContract*> AllQuestContracts;

};
