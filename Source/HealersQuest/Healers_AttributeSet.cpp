// (c)2018 - 2019 : Pocket Healer Games

#include "Healers_AttributeSet.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

UHealers_AttributeSet::UHealers_AttributeSet()
    : Level(1.f)
    , SkillPoints(1.f)
    , SkillPointsMax(1.f)
    , Health(1.f)
    , HealthMax(1.f)
    , Mana(0.f)
    , ManaMax(0.f)
    , AttackAccuracy(1.0f)
    , AttackPower(1.0f)
    , EvasionValue(0.0f)
    , ArmorValue(1.0f)
{
}

void UHealers_AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UHealers_AttributeSet, Level);
    
    DOREPLIFETIME(UHealers_AttributeSet, SkillPoints);
    DOREPLIFETIME(UHealers_AttributeSet, SkillPointsMax);

    DOREPLIFETIME(UHealers_AttributeSet, Health);
    DOREPLIFETIME(UHealers_AttributeSet, HealthMax);

    DOREPLIFETIME(UHealers_AttributeSet, Mana);
    DOREPLIFETIME(UHealers_AttributeSet, ManaMax);
    DOREPLIFETIME(UHealers_AttributeSet, ManaRegenerationPerSecond);

/*    DOREPLIFETIME(UHealers_AttributeSet, AttackPower);
    DOREPLIFETIME(UHealers_AttributeSet, DefensePower);
    DOREPLIFETIME(UHealers_AttributeSet, MoveSpeed);*/
}

void UHealers_AttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    // This is called whenever attributes change, so for max health/mana we want to scale the current totals to match
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetHealthMaxAttribute())
    {
        AdjustAttributeForMaxChange(Health, HealthMax, NewValue, GetHealthAttribute());
    }
    else if (Attribute == GetManaMaxAttribute())
    {
        AdjustAttributeForMaxChange(Mana, ManaMax, NewValue, GetManaAttribute());
    }
}

void UHealers_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    //FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
    //UAbilitySystemComponent* Source = Context.GetOriginalInstigatorAbilitySystemComponent();
    //const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();

    //// Compute the delta between old and new, if it is available
    //float DeltaValue = 0;
    //if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive)
    //{
    //    // If this was additive, store the raw delta value to be passed along later
    //    DeltaValue = Data.EvaluatedData.Magnitude;
    //}

    //// Get the Target actor, which should be our owner
    //AActor* TargetActor = nullptr;
    //AController* TargetController = nullptr;
    //ARPGCharacterBase* TargetCharacter = nullptr;
    //if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
    //{
    //    TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
    //    TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
    //    TargetCharacter = Cast<ARPGCharacterBase>(TargetActor);
    //}

    //if (Data.EvaluatedData.Attribute == GetDamageAttribute())
    //{
    //    // Get the Source actor
    //    AActor* SourceActor = nullptr;
    //    AController* SourceController = nullptr;
    //    ARPGCharacterBase* SourceCharacter = nullptr;
    //    if (Source && Source->AbilityActorInfo.IsValid() && Source->AbilityActorInfo->AvatarActor.IsValid())
    //    {
    //        SourceActor = Source->AbilityActorInfo->AvatarActor.Get();
    //        SourceController = Source->AbilityActorInfo->PlayerController.Get();
    //        if (SourceController == nullptr && SourceActor != nullptr)
    //        {
    //            if (APawn* Pawn = Cast<APawn>(SourceActor))
    //            {
    //                SourceController = Pawn->GetController();
    //            }
    //        }

    //        // Use the controller to find the source pawn
    //        if (SourceController)
    //        {
    //            SourceCharacter = Cast<ARPGCharacterBase>(SourceController->GetPawn());
    //        }
    //        else
    //        {
    //            SourceCharacter = Cast<ARPGCharacterBase>(SourceActor);
    //        }

    //        // Set the causer actor based on context if it's set
    //        if (Context.GetEffectCauser())
    //        {
    //            SourceActor = Context.GetEffectCauser();
    //        }
    //    }

    //    // Try to extract a hit result
    //    FHitResult HitResult;
    //    if (Context.GetHitResult())
    //    {
    //        HitResult = *Context.GetHitResult();
    //    }

    //    // Store a local copy of the amount of damage done and clear the damage attribute
    //    const float LocalDamageDone = GetDamage();
    //    SetDamage(0.f);

    //    if (LocalDamageDone > 0)
    //    {
    //        // Apply the health change and then clamp it
    //        const float OldHealth = GetHealth();
    //        SetHealth(FMath::Clamp(OldHealth - LocalDamageDone, 0.0f, GetMaxHealth()));

    //        if (TargetCharacter)
    //        {
    //            // This is proper damage
    //            TargetCharacter->HandleDamage(LocalDamageDone, HitResult, SourceTags, SourceCharacter, SourceActor);

    //            // Call for all health changes
    //            TargetCharacter->HandleHealthChanged(-LocalDamageDone, SourceTags);
    //        }
    //    }
    //}
    //else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    //{
    //    // Handle other health changes such as from healing or direct modifiers
    //    // First clamp it
    //    SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));

    //    if (TargetCharacter)
    //    {
    //        // Call for all health changes
    //        TargetCharacter->HandleHealthChanged(DeltaValue, SourceTags);
    //    }
    //}
    //else if (Data.EvaluatedData.Attribute == GetManaAttribute())
    //{
    //    // Clamp mana
    //    SetMana(FMath::Clamp(GetMana(), 0.0f, GetMaxMana()));

    //    if (TargetCharacter)
    //    {
    //        // Call for all mana changes
    //        TargetCharacter->HandleManaChanged(DeltaValue, SourceTags);
    //    }
    //}
    //else if (Data.EvaluatedData.Attribute == GetMoveSpeedAttribute())
    //{
    //    if (TargetCharacter)
    //    {
    //        // Call for all movespeed changes
    //        TargetCharacter->HandleMoveSpeedChanged(DeltaValue, SourceTags);
    //    }
    //}
}

void UHealers_AttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
    UAbilitySystemComponent* AbilityComponent = GetOwningAbilitySystemComponent();
    const float CurrentMaxValue = MaxAttribute.GetCurrentValue();
    if (!FMath::IsNearlyEqual(CurrentMaxValue, NewMaxValue) && AbilityComponent)
    {
        // Change current value to maintain the current Val / Max percent
        const float CurrentValue = AffectedAttribute.GetCurrentValue();
        float NewDelta = (CurrentMaxValue > 0.f) ? (CurrentValue * NewMaxValue / CurrentMaxValue) - CurrentValue : NewMaxValue;

        AbilityComponent->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Additive, NewDelta);
    }
}

void UHealers_AttributeSet::OnRep_Level()
{
}

void UHealers_AttributeSet::OnRep_SkillPoints()
{
}

void UHealers_AttributeSet::OnRep_SkillPointsMax()
{
}

void UHealers_AttributeSet::OnRep_Health()
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UHealers_AttributeSet, Health);
}

void UHealers_AttributeSet::OnRep_HealthMax()
{
}

void UHealers_AttributeSet::OnRep_Mana()
{
}

void UHealers_AttributeSet::OnRep_ManaMax()
{
}

void UHealers_AttributeSet::OnRep_ManaRegenerationPerSecond()
{
}