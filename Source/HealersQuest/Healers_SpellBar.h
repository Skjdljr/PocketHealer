// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "HealersQuest/Healers_Character.h"

#include "Healers_SpellBar.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declaration

class AHealers_Spell;

/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_SpellBar : public AActor
{
    GENERATED_BODY()

    AHealers_SpellBar();

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|SpellBar")
    AHealers_Character* Caster;

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|SpellBar")
    //AHealers_Spell* SelectedSpell;

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Healers|SpellBar")
    //TArray<AHealers_Spell*> SpellBar;

    UFUNCTION(BlueprintCallable, Category = "Healers|SpellBar")
    bool SelectSpell(int32 Index);
};