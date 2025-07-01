// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CharacterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DYNAMICOPENWORLD_API ACharacterPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
    virtual void SetupInputComponent() override;
    virtual void BeginPlay() override;

    void HandleClick();

    // Ŭ������ ������ ĳ���� ���� ����
    UPROPERTY()
    class ADynamicOpenWorldCharacter* ControlledCharacter;


};
