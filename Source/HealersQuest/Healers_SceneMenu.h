// (c)2018 - 2019 : Pocket Healer Games

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Healers_SceneMenu.generated.h"

/**
 * 
 */
UCLASS()
class HEALERSQUEST_API UHealers_SceneMenu : public UUserWidget
{
    GENERATED_BODY()
    
    UHealers_SceneMenu(const FObjectInitializer& ObjectInitializer);

public:

    UFUNCTION()
    void OpenScene();

    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OpenScene"), Category = "SceneMenu")
    void BP_OpenScene();

    UFUNCTION(BlueprintCallable, Category = "SceneMenu")
    void CloseScene(TSubclassOf<UHealers_SceneMenu> NextScene);

    UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "CloseScene"), Category = "SceneMenu")
    void BP_CloseScene(TSubclassOf<UHealers_SceneMenu> NextScene);

    UFUNCTION(BlueprintCallable, Category = "SceneMenu")
    void EndCloseScene(TSubclassOf<UHealers_SceneMenu> NextScene);
};
