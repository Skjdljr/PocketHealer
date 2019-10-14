// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"

#include "Healers_Character.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

class UHealers_AbilitySystemComponent;
class UHealers_AttributeSet;
class UHealers_GameplayAbility;

/////////////////////////////////////////////////////////////////////////////////////////////////

/** Struct representing a slot for an item, shown in the UI */
USTRUCT(BlueprintType)
struct HEALERSQUEST_API FRPGItemSlot
{
    GENERATED_BODY()

        /** Constructor, -1 means an invalid slot */
        FRPGItemSlot()
        : SlotNumber(-1)
    {}

    FRPGItemSlot(const FPrimaryAssetType& InItemType, int32 InSlotNumber)
        : ItemType(InItemType)
        , SlotNumber(InSlotNumber)
    {}

    /** The type of items that can go in this slot */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
        FPrimaryAssetType ItemType;

    /** The number of this slot, 0 indexed */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
        int32 SlotNumber;

    /** Equality operators */
    bool operator==(const FRPGItemSlot& Other) const
    {
        return ItemType == Other.ItemType && SlotNumber == Other.SlotNumber;
    }
    bool operator!=(const FRPGItemSlot& Other) const
    {
        return !(*this == Other);
    }

    /** Implemented so it can be used in Maps/Sets */
    friend inline uint32 GetTypeHash(const FRPGItemSlot& Key)
    {
        uint32 Hash = 0;

        Hash = HashCombine(Hash, GetTypeHash(Key.ItemType));
        Hash = HashCombine(Hash, (uint32)Key.SlotNumber);
        return Hash;
    }

    /** Returns true if slot is valid */
    bool IsValid() const
    {
        return ItemType.IsValid() && SlotNumber >= 0;
    }
};

/////////////////////////////////////////////////////////////////////////////////////////////////

UCLASS()
class HEALERSQUEST_API AHealers_Character : public ACharacter,
    public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AHealers_Character();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:	
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // Implement IAbilitySystemInterface
    UAbilitySystemComponent* GetAbilitySystemComponent() const override;

    /** Returns the character level that is passed to the ability system */
    UFUNCTION(BlueprintCallable)
    virtual int32 GetCharacterLevel() const;

    /** Modifies the character level, this may change abilities. Returns true on success */
    UFUNCTION(BlueprintCallable)
    virtual bool SetCharacterLevel(int32 NewLevel);

    /**
    * Apply the startup gameplay abilities and effects
    */
    virtual void AddStartupGameplayAbilities();

    /** Attempts to remove any startup gameplay abilities */
    void RemoveStartupGameplayAbilities();

    /** Adds slotted item abilities if needed */
    void AddSlottedGameplayAbilities();

    /** Remove slotted gameplay abilities, if force is false it only removes invalid ones */
    void RemoveSlottedGameplayAbilities(bool bRemoveAll);

    /** Fills in with ability specs, based on defaults and inventory */
    void FillSlottedAbilitySpecs(TMap<FRPGItemSlot, FGameplayAbilitySpec>& SlottedAbilitySpecs);


protected:


    /*
    * Ability System Component
    */
    UPROPERTY()
    UHealers_AbilitySystemComponent* AbilitySystemComponent;

    /**
    * Attribute Set
    */
    UPROPERTY()
    UHealers_AttributeSet* AttributeSet;

    UPROPERTY()
    int32 bAbilitiesInitialized;

    /** The level of this character, should not be modified directly once it has already spawned */
    UPROPERTY(Replicated, EditAnywhere, Category = "Abilities")
    int32 CharacterLevel;

    /** Abilities to grant to this character on creation. These will be activated by tag or event and are not bound to specific inputs */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
    TArray<TSubclassOf<UHealers_GameplayAbility>> GameplayAbilities;

    /** Map of item slot to gameplay ability class, these are bound before any abilities added by the inventory */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Abilities)
    TMap<FRPGItemSlot, TSubclassOf<UHealers_GameplayAbility>> DefaultSlottedAbilities;

    /** Passive gameplay effects applied on creation */
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
    TArray<TSubclassOf<UGameplayEffect>> PassiveGameplayEffects;

    /** Map of slot to ability granted by that slot. I may refactor this later */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
    TMap<FRPGItemSlot, FGameplayAbilitySpecHandle> SlottedAbilities;
};
