// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"

#include "Healers_PartySheet.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

class AHealers_CharacterSheet;

/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Store Information about our Party
 */
UCLASS(BlueprintType, Blueprintable)
class HEALERSQUEST_API AHealers_PartySheet : public AInfo
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (Deprecated), Category = "Healers|PartySheet")
	AHealers_CharacterSheet* PlayerCharacterSheet;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|PartySheet")
	TArray<AHealers_CharacterSheet*> PartyMembers;
};
