// Fill out your copyright notice in the Description page of Project Settings.


#include "PID.h"

// Sets default values
APID::APID()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	//PrimaryActorTick.bCanEverTick = true;

	Kp = 0.4f;

	Ki = 0.5f;

	Kd = 0.03f;

}

// Called when the game starts or when spawned
void APID::BeginPlay()
{
	Super::BeginPlay();	
	
}

// Called every frame
void APID::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APID::GetSpeedError(float AS, float TS)
{
	ActualSpeed = AS;
	TargetSpeed = TS;

	SpeedError = TargetSpeed - ActualSpeed;

}

void APID::GetFirstErrorDerv(float Delta)
{
	SpeedErrorDer = (SpeedError - PrevSpeedError) / Delta;

	PrevSpeedError = SpeedError;
}

void APID::GetIntegralOfError(float Delta)
{
	AccuSpeedError += SpeedError * Delta;
}

float APID::GetControllerActions(float Delta, float TS, float AS)
{

	GetSpeedError(AS, TS);
	GetFirstErrorDerv(Delta);
	GetIntegralOfError(Delta);

	float U_P = Kp * SpeedError + Ki * AccuSpeedError + Kd * SpeedErrorDer;

	return U_P;

}



