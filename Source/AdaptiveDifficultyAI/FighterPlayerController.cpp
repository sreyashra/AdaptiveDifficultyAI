// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputActionValue.h"
#include "FighterBase.h"

void AFighterPlayerController::SetControlledFighter(AFighterBase* Fighter)
{
	ControlledFighter = Fighter;
}

void AFighterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				InputSystem->AddMappingContext(InputMappingContext, 0);
			}
		}
		
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFighterPlayerController::HandlePlayerAction, EPlayerAction::Move);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AFighterPlayerController::HandlePlayerAction, EPlayerAction::Jump);
		EnhancedInputComponent->BindAction(BlockAction, ETriggerEvent::Triggered, this, &AFighterPlayerController::HandlePlayerAction, EPlayerAction::Block);
		EnhancedInputComponent->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &AFighterPlayerController::HandlePlayerAction, EPlayerAction::Dodge);
		EnhancedInputComponent->BindAction(Attack1Action, ETriggerEvent::Triggered, this, &AFighterPlayerController::HandlePlayerAction, EPlayerAction::Attack1);
		EnhancedInputComponent->BindAction(Attack2Action, ETriggerEvent::Triggered, this, &AFighterPlayerController::HandlePlayerAction, EPlayerAction::Attack2);
		EnhancedInputComponent->BindAction(SpecialAttack1Action, ETriggerEvent::Triggered, this, &AFighterPlayerController::HandlePlayerAction, EPlayerAction::SpecialAttack1);
		EnhancedInputComponent->BindAction(SpecialAttack2Action, ETriggerEvent::Triggered, this, &AFighterPlayerController::HandlePlayerAction, EPlayerAction::SpecialAttack2);
	}
}

void AFighterPlayerController::HandlePlayerAction(const FInputActionValue& Value, EPlayerAction Action)
{
	if(ControlledFighter)
	{
		switch (Action)
		{
		case EPlayerAction::Move:
			ControlledFighter->Move(Value.Get<float>());
			break;
		case EPlayerAction::Jump:
			ControlledFighter->Jump();
			break;
		case EPlayerAction::Block:
			ControlledFighter->Block();
			break;
		case EPlayerAction::Dodge:
			ControlledFighter->Dodge();
			break;
		case EPlayerAction::Attack1:
			ControlledFighter->Attack1();
			break;
		case EPlayerAction::Attack2:
			ControlledFighter->Attack2();
			break;
		case EPlayerAction::SpecialAttack1:
			ControlledFighter->SpecialAttack1();
			break;
		case EPlayerAction::SpecialAttack2:
			ControlledFighter->SpecialAttack2();
			break;
		}
	}
}
