// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_PlayerController.h"
#include "HealersQuest.h"
#include "Engine/World.h"

//UMG
#include "SlateBasics.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

AHealers_PlayerController::AHealers_PlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void AHealers_PlayerController::BeginPlay()
{
	Super::BeginPlay();
}