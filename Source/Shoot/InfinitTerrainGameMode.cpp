// Fill out your copyright notice in the Description page of Project Settings.

#include "InfinitTerrainGameMode.h"

AInfinitTerrainGameMode::AInfinitTerrainGameMode()
 {
	//NavMeshBoundsVolumePool = CreateDefaultSubobject<UMyPool>(FName("Nav Mesh Bounds Volume Pool"));
	}

//void AInfinitTerrainGameMode::PopulateBoundsVolumePool()
//{
//	TActorIterator<ANavMeshBoundsVolume> VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
//	while (VolumeIterator)
//		{
//		AddToPool(*VolumeIterator);
//		++VolumeIterator;
//		}
//	}
//
//
//void AInfinitTerrainGameMode::AddToPool(ANavMeshBoundsVolume* VolumeToAdd)
// {
//	if (VolumeToAdd == nullptr) { return; }
//	UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), *VolumeToAdd->GetName());
//	}
