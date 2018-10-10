
#include "Healers_PlayerController.h"
#include "Healers_PlayerState.h"
#include "Healers_PartySheet.h"
#include "Healers_FunctionLibrary.h"

float UHealers_FunctionLibrary::PseudoRandomChance(float BaseChance, int32 Counter)
{
	float FinalChance = BaseChance;

	if (Counter > 1)
	{
		FinalChance += BaseChance * Counter;
	}

	return FinalChance;
}

bool UHealers_FunctionLibrary::IsRandomSuccess(const float BaseChance, const int32 Counter)
{
	bool IsSuccess = false;

	float ChanceValue = FMath::FRand();
	if (ChanceValue > PseudoRandomChance(BaseChance, Counter))
	{
		IsSuccess = true;
	}
	
	return IsSuccess;
}

AHealers_PartySheet* UHealers_FunctionLibrary::GetPartySheet(APlayerController* PC)
{
	AHealers_PartySheet* PartySheet = nullptr;
	if (PC)
	{
		if (auto PS = Cast<AHealers_PlayerState>(PC->PlayerState))
		{
			PartySheet = PS->PartySheet;
		}
	}
	return PartySheet;
}
