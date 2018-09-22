// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Healers_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_PlayerController : public APlayerController
{
    GENERATED_UCLASS_BODY()

public:

    // Override BeginPlay()
    virtual void BeginPlay() override;

    // Character reference, Party reference ?
};
