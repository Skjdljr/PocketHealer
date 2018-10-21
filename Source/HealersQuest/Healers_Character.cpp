// Fill out your copyright notice in the Description page of Project Settings.

#include "Healers_Character.h"


// Sets default values
AHealers_Character::AHealers_Character()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHealers_Character::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void AHealers_Character::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHealers_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

