

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
