// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "Patrol_Guy.generated.h"

/**
 * 
 */
UCLASS()
class SHOOT_API APatrol_Guy : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPointsCPP;
	
	
};
