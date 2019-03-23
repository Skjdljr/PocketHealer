// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Healers_GameInstance.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API UHealers_GameInstance : public UGameInstance
{
    GENERATED_BODY()
    
public:
    
    // Reference UMG Asset in the Editor
    UPROPERTY(BlueprintReadOnly, Category = "GameMode")
    UUserWidget* MainMenu;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
    TSubclassOf<class UUserWidget> MainMenuClass;

    UPROPERTY(BlueprintReadOnly, Category = "GameMode")
    UUserWidget* GameMenu;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
    TSubclassOf<class UUserWidget> GameMenuClass;
};
