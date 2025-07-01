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

    // 클릭으로 제어할 캐릭터 직접 참조
    UPROPERTY()
    class ADynamicOpenWorldCharacter* ControlledCharacter;


};
