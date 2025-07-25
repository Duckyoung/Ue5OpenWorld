// Copyright Epic Games, Inc. All Rights Reserved.

#include "DynamicOpenWorldGameMode.h"
#include "DynamicOpenWorldCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "CharacterPlayerController.h"

ADynamicOpenWorldGameMode::ADynamicOpenWorldGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PlayerControllerClass = ACharacterPlayerController::StaticClass();
}
