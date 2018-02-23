// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShootGameMode.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "MyPool.h"
#include "InfinitTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOT_API AInfinitTerrainGameMode : public AShootGameMode
{
	GENERATED_BODY()
	
		public:
			AInfinitTerrainGameMode();
			//UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
				// void PopulateBoundsVolumePool();
protected:
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pool")
	//UMyPool* NavMeshBoundsVolumePool;
private:
		//void AddToPool( ANavMeshBoundsVolume *VolumeToAdd);
	
	
};
