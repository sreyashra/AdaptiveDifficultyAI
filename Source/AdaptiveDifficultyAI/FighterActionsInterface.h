// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FighterActionsInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UFighterActionsInterface : public UInterface
{
	GENERATED_BODY()
};

class IFighterActionsInterface
{
	GENERATED_BODY()

public:
	virtual void Move(float Value) = 0;
	virtual void Jump() = 0;
	virtual void Block() = 0;
	virtual void Dodge() = 0;
	virtual void Attack1() = 0;
	virtual void Attack2() = 0;
	virtual void SpecialAttack1() = 0;
	virtual void SpecialAttack2() = 0;
	
};
