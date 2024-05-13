// Fill out your copyright notice in the Description page of Project Settings.


#include "OneVsOneGameMode.h"
#include "FighterPlayerController.h"
#include "FighterBase.h"


void AOneVsOneGameMode::StartPlay()
{
	Super::StartPlay();

	if(APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController())
	{
		if (AFighterPlayerController* FighterPlayerController = Cast<AFighterPlayerController>(PlayerController))
		{
			/*if (AFighterBase* Character = Cast<AFighterBase>(SpawnDefaultPawnFor(FighterPlayerController, nullptr)))
			{
				FighterPlayerController->SetControlledFighter(Character);
				FighterPlayerController->Possess(Character);
			}*/
		}
	}
}

APawn* AOneVsOneGameMode::SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	return GetWorld()->SpawnActor<AFighterBase>(DefaultPawnClass, StartSpot->GetTransform(), SpawnParams);
}
