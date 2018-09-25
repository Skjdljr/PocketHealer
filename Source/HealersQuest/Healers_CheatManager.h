

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "Healers_CheatManager.generated.h"

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API UHealers_CheatManager : public UCheatManager
{
	GENERATED_BODY()

	UFUNCTION(exec, Category = "Healers|Cheat")
	void Cheat_DisplayQuestMenu();
};
