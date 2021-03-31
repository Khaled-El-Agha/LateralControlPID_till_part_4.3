// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PID.generated.h"

UCLASS()
class LATERALCONTROLPID_API APID : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APID();

	/** The current ActualSpeed as a string  */
	UPROPERTY(Category = Control, EditAnyWhere, BlueprintReadWrite)
	float ActualSpeed;

	/** The current TargetSpeed as a string  */
	UPROPERTY(Category = Control, EditAnyWhere, BlueprintReadWrite)
	float TargetSpeed;

	/** The current TargetSpeed as a string  */
	UPROPERTY(Category = Control, EditAnyWhere, BlueprintReadWrite)
	float PrevSpeedError;

	/** The current TargetSpeed as a string  */
	UPROPERTY(Category = Control, EditAnyWhere, BlueprintReadWrite)
	float AccuSpeedError;

	/** The current TargetSpeed as a string  */
	UPROPERTY(Category = Control, EditAnyWhere, BlueprintReadWrite)
	float SpeedErrorDer;

	/** The current TargetSpeed as a string  */
	UPROPERTY(Category = Control, EditAnyWhere, BlueprintReadWrite)
	float SpeedError;

	/** The current TargetSpeed as a string  */
	UPROPERTY(Category = Control, EditAnyWhere, BlueprintReadWrite)
	float Kp;

	/** The current TargetSpeed as a string  */
	UPROPERTY(Category = Control, EditAnyWhere, BlueprintReadWrite)
	float Ki;

	/** The current TargetSpeed as a string  */
	UPROPERTY(Category = Control, EditAnyWhere, BlueprintReadWrite)
	float Kd;

	// The controller model
	
	UFUNCTION(BlueprintCallable,Category = "Control")
	float GetControllerActions(float Delta, float TS, float AS);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	void GetFirstErrorDerv(float Delta);

	void GetIntegralOfError(float Delta);

	void GetSpeedError(float AS, float TS);

};
