// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_Character.h"

#include "UnrealNetwork.h"
#include "Abilities/GameplayAbilityTypes.h"

#include "Healers_AbilitySystemComponent.h"
#include "Healers_AttributeSet.h"
#include "Healers_GameplayAbility.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

// Sets default values
AHealers_Character::AHealers_Character()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;


    AbilitySystemComponent = CreateDefaultSubobject<UHealers_AbilitySystemComponent>("AbilitySystemComponent");

    // Create the attribute set, this replicates by default
    AttributeSet = CreateDefaultSubobject<UHealers_AttributeSet>(TEXT("AttributeSet"));
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void AHealers_Character::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AHealers_Character, CharacterLevel);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

// Called when the game starts or when spawned
void AHealers_Character::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void AHealers_Character::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHealers_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AHealers_Character::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

int32 AHealers_Character::GetCharacterLevel() const
{
    return CharacterLevel;
}

bool AHealers_Character::SetCharacterLevel(int32 NewLevel)
{
    bool bSuccessful{ false };

    if (CharacterLevel != NewLevel && NewLevel > 0)
    {
        // Our level changed so we need to refresh abilities
        RemoveStartupGameplayAbilities();
        CharacterLevel = NewLevel;
        AddStartupGameplayAbilities();

        bSuccessful = true;
    }

    return bSuccessful;
}

void AHealers_Character::AddStartupGameplayAbilities()
{
    check(AbilitySystemComponent);

    if (Role == ROLE_Authority && !bAbilitiesInitialized)
    {
        // Grant abilities, but only on the server	
        for (TSubclassOf<UHealers_GameplayAbility>& StartupAbility : GameplayAbilities)
        {
            AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility, GetCharacterLevel(), INDEX_NONE, this));
        }

        // Now apply passives
        for (TSubclassOf<UGameplayEffect>& GameplayEffect : PassiveGameplayEffects)
        {
            FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
            EffectContext.AddSourceObject(this);

            FGameplayEffectSpecHandle NewHandle = AbilitySystemComponent->MakeOutgoingSpec(GameplayEffect, GetCharacterLevel(), EffectContext);
            if (NewHandle.IsValid())
            {
                FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), AbilitySystemComponent);
            }
        }

        AddSlottedGameplayAbilities();

        bAbilitiesInitialized = true;
    }
}

void AHealers_Character::RemoveStartupGameplayAbilities()
{
    check(AbilitySystemComponent);

    if (Role == ROLE_Authority && bAbilitiesInitialized)
    {
        // Remove any abilities added from a previous call
        TArray<FGameplayAbilitySpecHandle> AbilitiesToRemove;
        for (const FGameplayAbilitySpec& Spec : AbilitySystemComponent->GetActivatableAbilities())
        {
            if ((Spec.SourceObject == this) && GameplayAbilities.Contains(Spec.Ability->GetClass()))
            {
                AbilitiesToRemove.Add(Spec.Handle);
            }
        }

        // Do in two passes so the removal happens after we have the full list
        for (int32 i = 0; i < AbilitiesToRemove.Num(); i++)
        {
            AbilitySystemComponent->ClearAbility(AbilitiesToRemove[i]);
        }

        // Remove all of the passive gameplay effects that were applied by this character
        FGameplayEffectQuery Query;
        Query.EffectSource = this;
        AbilitySystemComponent->RemoveActiveEffects(Query);

        RemoveSlottedGameplayAbilities(true);

        bAbilitiesInitialized = false;
    }
}

void AHealers_Character::AddSlottedGameplayAbilities()
{
    TMap<FRPGItemSlot, FGameplayAbilitySpec> SlottedAbilitySpecs;
    FillSlottedAbilitySpecs(SlottedAbilitySpecs);

    // Now add abilities if needed
    for (const TPair<FRPGItemSlot, FGameplayAbilitySpec>& SpecPair : SlottedAbilitySpecs)
    {
        FGameplayAbilitySpecHandle& SpecHandle = SlottedAbilities.FindOrAdd(SpecPair.Key);

        if (!SpecHandle.IsValid())
        {
            SpecHandle = AbilitySystemComponent->GiveAbility(SpecPair.Value);
        }
    }
}

void AHealers_Character::RemoveSlottedGameplayAbilities(bool bRemoveAll)
{
    TMap<FRPGItemSlot, FGameplayAbilitySpec> SlottedAbilitySpecs;

    if (!bRemoveAll)
    {
        // Fill in map so we can compare
        FillSlottedAbilitySpecs(SlottedAbilitySpecs);
    }

    for (TPair<FRPGItemSlot, FGameplayAbilitySpecHandle>& ExistingPair : SlottedAbilities)
    {
        FGameplayAbilitySpec* FoundSpec = AbilitySystemComponent->FindAbilitySpecFromHandle(ExistingPair.Value);
        bool bShouldRemove = bRemoveAll || !FoundSpec;

        if (!bShouldRemove)
        {
            // Need to check desired ability specs, if we got here FoundSpec is valid
            FGameplayAbilitySpec* DesiredSpec = SlottedAbilitySpecs.Find(ExistingPair.Key);

            if (!DesiredSpec || DesiredSpec->Ability != FoundSpec->Ability || DesiredSpec->SourceObject != FoundSpec->SourceObject)
            {
                bShouldRemove = true;
            }
        }

        if (bShouldRemove)
        {	
            if (FoundSpec)
            {
                // Need to remove registered ability
                AbilitySystemComponent->ClearAbility(ExistingPair.Value);
            }

            // Make sure handle is cleared even if ability wasn't found
            ExistingPair.Value = FGameplayAbilitySpecHandle();
        }
    }
}

void AHealers_Character::FillSlottedAbilitySpecs(TMap<FRPGItemSlot, FGameplayAbilitySpec>& SlottedAbilitySpecs)
{
    // First add default ones
    for (const TPair<FRPGItemSlot, TSubclassOf<UHealers_GameplayAbility>>& DefaultPair : DefaultSlottedAbilities)
    {
        if (DefaultPair.Value.Get())
        {
            SlottedAbilitySpecs.Add(DefaultPair.Key, FGameplayAbilitySpec(DefaultPair.Value, GetCharacterLevel(), INDEX_NONE, this));
        }
    }

    // Now potentially override with inventory
    //if (InventorySource)
    //{
    //    const TMap<FRPGItemSlot, URPGItem*>& SlottedItemMap = InventorySource->GetSlottedItemMap();

    //    for (const TPair<FRPGItemSlot, URPGItem*>& ItemPair : SlottedItemMap)
    //    {
    //        URPGItem* SlottedItem = ItemPair.Value;

    //        // Use the character level as default
    //        int32 AbilityLevel = GetCharacterLevel();

    //        if (SlottedItem && SlottedItem->ItemType.GetName() == FName(TEXT("Weapon")))
    //        {
    //            // Override the ability level to use the data from the slotted item
    //            AbilityLevel = SlottedItem->AbilityLevel;
    //        }

    //        if (SlottedItem && SlottedItem->GrantedAbility)
    //        {
    //            // This will override anything from default
    //            SlottedAbilitySpecs.Add(ItemPair.Key, FGameplayAbilitySpec(SlottedItem->GrantedAbility, AbilityLevel, INDEX_NONE, SlottedItem));
    //        }
    //    }
    //}
}

void AHealers_Character::GiveAbility(TSubclassOf<UHealers_GameplayAbility> InAbility, const int32 InAbilityLevel)
{
    if (InAbility == nullptr)
    {
        GAME_LOG(Game, Error, "InAbility was Null!");
        return;
    }

    check(AbilitySystemComponent);

    if (AbilitySystemComponent)
    {
        // @! TODO : Unsure of the purpose of InputID, seems to be related to input/keybinding
        const int32 InputID{ 0 }; //static_cast<int32>(Cast<UHealers_GameplayAbility>(InAbility.GetDefaultObject())->Input);

        AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(InAbility, InAbilityLevel, InputID, this));
    }
}
