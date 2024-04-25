// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FighterActionsInterface.h"
#include "GameFramework/Character.h"
#include "FighterBase.generated.h"

UCLASS()
class ADAPTIVEDIFFICULTYAI_API AFighterBase : public ACharacter, public IFighterActionsInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFighterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// ICharacterActions implementation
	virtual void Move(float Value) override;
	virtual void Jump() override;
	virtual void Block() override;
	virtual void Dodge() override;
	virtual void Attack1() override;
	virtual void Attack2() override;
	virtual void SpecialAttack1() override;
	virtual void SpecialAttack2() override;

protected:
	// Implementation methods
	void MoveImpl(float Value);
	void JumpImpl();
	void BlockImpl();
	void DodgeImpl();
	void Attack1Impl();
	void Attack2Impl();
	void SpecialAttack1Impl();
	void SpecialAttack2Impl();

};
