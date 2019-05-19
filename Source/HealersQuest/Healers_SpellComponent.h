// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Healers_SpellComponent.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

class AHealers_Spell;
class AHealers_CharacterSheet;

/////////////////////////////////////////////////////////////////////////////////////////////////

UCLASS(Blueprintable)
class HEALERSQUEST_API UHealers_SpellComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    /* Determines the amount of time before this component shuts down.
    If not positive, then this is an instance spell, and ShutdownSpell is never called. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Healers")
    float SpellDuration;

protected:
    float SpellLifespan;

public:

    /**
     * Invoked whenever the spell has been cast.
     */
    virtual void ExecuteSpell (AHealers_Spell* SpellOwner, AHealers_CharacterSheet* caster, const TArray<AHealers_CharacterSheet*>& Targets);

    /**
     * Invoked on every frame when this spell component is active.
     */
    virtual void TickSpell (float DeltaSec);

    /**
     * Invoked whenever enough time elapsed since this component was last cast.
     */
    virtual void ShutdownSpell();

    /**
     * Invoked whenever the spell owner actor is destroyed.
     */
    virtual void DestroySpellComponent();

    /**
     * Returns true if this spell is actively being ticked.
     */
    UFUNCTION(BlueprintCallable, Category="Healers")
    virtual bool IsSpellActive() const;

    UFUNCTION(BlueprintNativeEvent, Category="Healers")
    void BP_ExecuteSpell(AHealers_Spell* SpellOwner, AHealers_CharacterSheet* Caster, const TArray<AHealers_CharacterSheet*>& Targets);

    UFUNCTION(BlueprintNativeEvent, Category="Healers")
    void BP_TickSpell(float DeltaSec);

    UFUNCTION(BlueprintNativeEvent, Category="Healers")
    void BP_ShutdownSpell();

    UFUNCTION(BlueprintNativeEvent, Category="Healers")
    void BP_DestroySpellComponent();
};
