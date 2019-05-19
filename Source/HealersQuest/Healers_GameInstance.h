// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Healers_GameInstance.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

class UUserWidget;

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
    UPROPERTY(BlueprintReadOnly, Category = "Healers|GameInstance")
    UUserWidget* MainMenu;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healers|GameInstance")
    TSubclassOf<class UUserWidget> MainMenuClass;

    UPROPERTY(BlueprintReadOnly, Category = "Healers|GameInstance")
    UUserWidget* GameMenu;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healers|GameInstance")
    TSubclassOf<class UUserWidget> GameMenuClass;

    UPROPERTY(BlueprintReadOnly, Category = "Healers|GameInstance")
    UUserWidget* CharacterMenu;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Healers|GameInstance")
    TSubclassOf<class UUserWidget> CharacterMenuClass;
};
