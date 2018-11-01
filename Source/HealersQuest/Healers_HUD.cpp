// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_HUD.h"

//UMG
#include "SlateBasics.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

void AHealers_HUD::SetScene(TSubclassOf<UUserWidget> InSceneClass)
{
    if (auto World = GetWorld())
    {
        CurrentScene = CreateWidget<UUserWidget>(World, InSceneClass);
        if (CurrentScene)
        {
            CurrentScene->AddToViewport();
        }
    }
}


