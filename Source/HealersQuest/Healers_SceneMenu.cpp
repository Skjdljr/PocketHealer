// Fill out your copyright notice in the Description page of Project Settings.

/////////////////////////////////////////////////////////////////////////////////////////////////

#include "Healers_SceneMenu.h"
#include "Healers_HUD.h"

/////////////////////////////////////////////////////////////////////////////////////////////////

UHealers_SceneMenu::UHealers_SceneMenu(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{
    //
}

void UHealers_SceneMenu::OpenScene()
{
    // Delegate

    BP_OpenScene();
}

void UHealers_SceneMenu::CloseScene(TSubclassOf<UHealers_SceneMenu> NextScene)
{
    // Delegate

    BP_CloseScene(NextScene);
}

void UHealers_SceneMenu::EndCloseScene(TSubclassOf<UHealers_SceneMenu> NextScene) const
{
    if (auto PC = GetOwningPlayer())
    {
        if (auto HealersHUD = Cast<AHealers_HUD>(PC->GetHUD()))
        {
            HealersHUD->SetScene(NextScene);
        }
    }
}
