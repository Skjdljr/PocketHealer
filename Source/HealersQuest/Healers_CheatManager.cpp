
#include "Healers_CheatManager.h"
#include "Healers_PlayerController.h"
#include "Healers_HUD.h"

void UHealers_CheatManager::Cheat_DisplayQuestMenu()
{
	if (auto HealersPC = Cast<AHealers_PlayerController>(GetOuter()))
	{
		if (auto HealersHUD = Cast<AHealers_HUD>(HealersPC->GetHUD()))
		{
			// Do nothing for now. We need to figure out how we'll display this, etc.
		}
	}
}
