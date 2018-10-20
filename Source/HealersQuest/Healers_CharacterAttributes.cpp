#include "HealersQuest.h"
#include "Healers_CharacterAttributes.h"

#pragma region StructDamageResistance

FDamageResistance::FDamageResistance() :
	DamageType(EDamageResistance::DR_Null),
	DamageResistancePercentValue(0.0f),
	DamageResistanceValue(0.0f)
{
}

#pragma endregion StructDamageResistance