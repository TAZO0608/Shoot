// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "MyGrass.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOT_API UMyGrass : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyGrass();
	
		UPROPERTY(EditDefaultsOnly, Category = Spawning)
		 FBox SpawningExtents;
	UPROPERTY(EditDefaultsOnly, Category = Spawning)
		 int SpawnCount;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SpawnGrass();
	
};
