// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OneVsOneGameMode.generated.h"


UCLASS()
class ADAPTIVEDIFFICULTYAI_API AOneVsOneGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void StartPlay() override;
	virtual APawn* SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot) override;
};
