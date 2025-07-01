// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayerController.h"
#include "AIController.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "EngineUtils.h" 
#include "DynamicOpenWorldCharacter.h"
#include "NavigationSystem.h"
#include "NavigationInvokerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Controller.h"    

void ACharacterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	// Input binding for mouse click
	InputComponent->BindAction("ClickMove", IE_Pressed, this, &ACharacterPlayerController::HandleClick);
}

void ACharacterPlayerController::BeginPlay()
{
    Super::BeginPlay();
}


void ACharacterPlayerController::HandleClick()
{
    FHitResult Hit;
    GetHitResultUnderCursor(ECC_Visibility, false, Hit);

    if (!ControlledCharacter)
    {
        ControlledCharacter = Cast<ADynamicOpenWorldCharacter>( this->GetPawn());
    }

    FVector TargetLocation = Hit.Location;

    UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
    if (!NavSys)
    {
        UE_LOG(LogTemp, Error, TEXT("NavSys is null"));
        return;
    }

    FNavLocation ProjectedNavLocation;
    bool bOnNavMesh = NavSys->ProjectPointToNavigation(
        TargetLocation,
        ProjectedNavLocation,
        FVector(300, 300, 500)
    );

    UE_LOG(LogTemp, Warning, TEXT("클릭 위치 NavMesh 위에 있음? %s"), bOnNavMesh ? TEXT("Yes") : TEXT("No"));

    FNavLocation CharacterProjectedLocation;
    bool bCharacterOnNavMesh = NavSys->ProjectPointToNavigation(
        ControlledCharacter->GetActorLocation(),
        CharacterProjectedLocation,
        FVector(500, 500, 1000)
    );

    UE_LOG(LogTemp, Warning, TEXT("캐릭터 위치 NavMesh 위에 있음? %s"), bCharacterOnNavMesh ? TEXT("Yes") : TEXT("No"));

    if (bOnNavMesh && bCharacterOnNavMesh)
    {
        ControlledCharacter->MoveToTargetLocation(ProjectedNavLocation.Location);
        DrawDebugSphere(GetWorld(), ProjectedNavLocation.Location, 25.f, 12, FColor::Green, false, 2.0f);
    }
}
