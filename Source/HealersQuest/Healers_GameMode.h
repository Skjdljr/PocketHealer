// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Healers_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_GameMode : public AGameMode
{
	GENERATED_BODY()

	AHealers_GameMode(const class FObjectInitializer& ObjectInitializer);

public:

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
	UUserWidget* MainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
	TSubclassOf<class UUserWidget> MainMenuClass;

	// Override BeginPlay()
	virtual void BeginPlay() override;
	virtual void StartMatch() override;

};
