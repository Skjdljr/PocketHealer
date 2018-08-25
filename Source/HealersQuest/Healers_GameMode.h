// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API AHealers_GameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

public:

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
	UUserWidget* MainMenu;

	// Override BeginPlay()
	virtual void BeginPlay() override;
};
