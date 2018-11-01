// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Healers_HUD.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_HUD : public AHUD
{
    GENERATED_BODY()
    
public:

    UFUNCTION()
    void SetScene(TSubclassOf<UUserWidget> InSceneClass);

    UPROPERTY()
    UUserWidget* CurrentScene;
    
    
};
