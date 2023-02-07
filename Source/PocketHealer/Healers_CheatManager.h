// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "Healers_CheatManager.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 
 */
UCLASS()
class POCKETHEALER_API UHealers_CheatManager : public UCheatManager
{
	GENERATED_BODY()

	UFUNCTION(exec, Category = "Healers|Cheat")
	void Cheat_DisplayQuestMenu() const;
};
