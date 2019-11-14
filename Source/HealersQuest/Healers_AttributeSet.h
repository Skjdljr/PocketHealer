// (c)2018 - 2019 : Pocket Healer Games

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"

#include "HealersQuest.h"
#include "Healers_AttributeSet.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API UHealers_AttributeSet : public UAttributeSet
{
    GENERATED_BODY()
    
public:

    UHealers_AttributeSet();
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    /////////////////////////////////////////////////////////////////////////////////////////////////

    UPROPERTY(ReplicatedUsing=OnRep_Level, BlueprintReadWrite, EditInstanceOnly, Category = "CharacterAttributes")
    FGameplayAttributeData Level;
    ATTRIBUTE_ACCESSORS(UHealers_AttributeSet, Level)

    ////////========////////

    UPROPERTY(ReplicatedUsing=OnRep_SkillPoints, BlueprintReadWrite, EditInstanceOnly, Category = "CharacterAttributes")
    FGameplayAttributeData SkillPoints;
    ATTRIBUTE_ACCESSORS(UHealers_AttributeSet, SkillPoints)

    UPROPERTY(ReplicatedUsing=OnRep_SkillPointsMax, BlueprintReadWrite, EditInstanceOnly, Category = "CharacterAttributes")
    FGameplayAttributeData SkillPointsMax;
    ATTRIBUTE_ACCESSORS(UHealers_AttributeSet, SkillPointsMax)

    ////////========////////

    UPROPERTY(ReplicatedUsing=OnRep_Health, BlueprintReadWrite, EditInstanceOnly, Category = "CharacterAttributes")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UHealers_AttributeSet, Health)

    UPROPERTY(ReplicatedUsing=OnRep_HealthMax, BlueprintReadWrite, EditInstanceOnly, Category = "CharacterAttributes")
    FGameplayAttributeData HealthMax;
    ATTRIBUTE_ACCESSORS(UHealers_AttributeSet, HealthMax)

    ////////========////////

    UPROPERTY(ReplicatedUsing=OnRep_Mana, BlueprintReadWrite, EditInstanceOnly, Category = "CharacterAttributes")
    FGameplayAttributeData Mana;
    ATTRIBUTE_ACCESSORS(UHealers_AttributeSet, Mana)

    UPROPERTY(ReplicatedUsing=OnRep_ManaMax, BlueprintReadWrite, EditInstanceOnly, Category = "CharacterAttributes")
    FGameplayAttributeData ManaMax;
    ATTRIBUTE_ACCESSORS(UHealers_AttributeSet, ManaMax)

    UPROPERTY(ReplicatedUsing=OnRep_ManaRegenerationPerSecond, BlueprintReadWrite, EditInstanceOnly, Category = "CharacterAttributes")
    FGameplayAttributeData ManaRegenerationPerSecond;
    ATTRIBUTE_ACCESSORS(UHealers_AttributeSet, ManaRegenerationPerSecond)

    ////////========////////

    UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "CharacterAttributes")
    FGameplayAttributeData Initiative;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    FGameplayAttributeData InitiativePerSecond;

    ////////========////////

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    FGameplayAttributeData AttackAccuracy;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    FGameplayAttributeData AttackPower;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    FGameplayAttributeData MagicAccuracy;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    FGameplayAttributeData MagicPower;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    FGameplayAttributeData CriticalDamageChance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    FGameplayAttributeData CriticalDamageValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    FGameplayAttributeData EvasionValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    FGameplayAttributeData ArmorValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    FGameplayAttributeData LuckValue;

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    //TArray<FDamageResistance> Resistances;

    //UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterAttributes")
    //TArray<TSubclassOf<AHealers_Spell>> Abilities;

protected:
    /** Helper function to proportionally adjust the value of an attribute when it's associated max attribute changes. (i.e. When MaxHealth increases, Health increases by an amount that maintains the same percentage as before) */
    void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty);

    // These OnRep functions exist to make sure that the ability system internal representations are synchronized properly during replication
    UFUNCTION()
    virtual void OnRep_Level();

    UFUNCTION()
    virtual void OnRep_SkillPoints();

    UFUNCTION()
    virtual void OnRep_SkillPointsMax();

    UFUNCTION()
    virtual void OnRep_Health();

    UFUNCTION()
    virtual void OnRep_HealthMax();

    UFUNCTION()
    virtual void OnRep_Mana();

    UFUNCTION()
    virtual void OnRep_ManaMax();

    UFUNCTION()
    virtual void OnRep_ManaRegenerationPerSecond();
};
