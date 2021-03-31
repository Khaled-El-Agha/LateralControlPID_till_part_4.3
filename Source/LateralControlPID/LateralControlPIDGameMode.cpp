// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "LateralControlPIDGameMode.h"
#include "LateralControlPIDPawn.h"
#include "LateralControlPIDHud.h"

ALateralControlPIDGameMode::ALateralControlPIDGameMode()
{
	DefaultPawnClass = ALateralControlPIDPawn::StaticClass();
	HUDClass = ALateralControlPIDHud::StaticClass();
}
