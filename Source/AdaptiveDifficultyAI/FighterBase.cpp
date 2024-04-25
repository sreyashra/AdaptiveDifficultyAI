// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterBase.h"
#include "FighterActionsInterface.h"

// Sets default values
AFighterBase::AFighterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFighterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFighterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFighterBase::Move(float Value)
{
	MoveImpl(Value);
}

void AFighterBase::Jump()
{
	JumpImpl();
}

void AFighterBase::Block()
{
	BlockImpl();
}

void AFighterBase::Dodge()
{
	DodgeImpl();
}

void AFighterBase::Attack1()
{
	Attack1Impl();
}

void AFighterBase::Attack2()
{
	Attack2Impl();
}

void AFighterBase::SpecialAttack1()
{
	SpecialAttack1Impl();
}

void AFighterBase::SpecialAttack2()
{
	SpecialAttack2Impl();
}

void AFighterBase::MoveImpl(float Value)
{
	//Movement logic here
}

void AFighterBase::JumpImpl()
{
	Super::Jump();

	//Additional jump logic here
}

void AFighterBase::BlockImpl()
{
	//blocking logic here
}

void AFighterBase::DodgeImpl()
{
	//dodge logic here
}

void AFighterBase::Attack1Impl()
{
	//attack 1 logic here
}

void AFighterBase::Attack2Impl()
{
	// Attack 2 logic here
}

void AFighterBase::SpecialAttack1Impl()
{
	// Special attack logic here
}

void AFighterBase::SpecialAttack2Impl()
{
	//special attack 2 logic here
}
