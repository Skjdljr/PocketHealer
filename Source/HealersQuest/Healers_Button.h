// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Healers_Button.generated.h"

/////////////////////////////////////////////////////////////////////////////////////////////////
// Forward Declarations

class UTextBlock;

/////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API UHealers_Button : public UButton
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound", meta = (DisplayName = "Unhovered Sound"))
	USoundBase* UnhoveredSlateSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound", meta = (DisplayName = "Text Widget"))
	UTextBlock* TextWidget;
};
