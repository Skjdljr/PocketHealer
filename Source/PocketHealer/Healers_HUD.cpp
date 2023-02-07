// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_HUD.h"

//UMG
#include "SlateBasics.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

#include "Healers_SceneMenu.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

void AHealers_HUD::SetScene(TSubclassOf<UUserWidget> InSceneClass)
{
    if (auto World = GetWorld())
    {
        if (auto PC = GetOwningPlayerController())
        {
            if (PC->IsLocalController())
            {
                CurrentWidget = CreateWidget<UUserWidget>(World, InSceneClass);
                if (auto CurrentScene = Cast<UHealers_SceneMenu>(CurrentWidget))
                {
                    CurrentScene->AddToViewport();
                    CurrentScene->OpenScene();
                }
            }
        }
    }
}