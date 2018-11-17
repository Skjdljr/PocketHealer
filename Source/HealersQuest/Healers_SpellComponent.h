// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Healers_SpellComponent.generated.h"

class AHealers_Spell;
class AHealers_CharacterSheet;

UCLASS(Blueprintable)
class HEALERSQUEST_API UHealers_SpellComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    /* Determines the amount of time before this component shutsdown.
    If not positive, then this is an instance spell, and ShutdownSpell is never called. */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Healers")
    float SpellDuration;

protected:
    float SpellLifespan;

public:

    /**
     * Invoked whenever the spell was casted.
     */
    virtual void ExecuteSpell (AHealers_Spell* spellOwner, AHealers_CharacterSheet* caster, const TArray<AHealers_CharacterSheet*>& targets);

    /**
     * Invoked on every frame when this spell component is active.
     */
    virtual void TickSpell (float deltaSec);

    /**
     * Invoked whenever enough time elapsed since this component was last casted.
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
    void BP_ExecuteSpell(AHealers_Spell* spellOwner, AHealers_CharacterSheet* caster, const TArray<AHealers_CharacterSheet*>& targets);

    UFUNCTION(BlueprintNativeEvent, Category="Healers")
    void BP_TickSpell(float deltaSec);

    UFUNCTION(BlueprintNativeEvent, Category="Healers")
    void BP_ShutdownSpell();

    UFUNCTION(BlueprintNativeEvent, Category="Healers")
    void BP_DestroySpellComponent();
};
