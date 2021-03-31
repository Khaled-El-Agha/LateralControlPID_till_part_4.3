// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LateralControlPIDHud.generated.h"

UCLASS(config = Game)
class ALateralControlPIDHud : public AHUD
{
	GENERATED_BODY()

public:
	ALateralControlPIDHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface

};
