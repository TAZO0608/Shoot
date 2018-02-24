// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPool.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationSystem.h"
#include "MyPros.generated.h"

UCLASS()
class SHOOT_API AMyPros : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPros();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void PlaceActors(TSubclassOf<AActor> ToSpawn,bool isPawn = false, int MinSpawn = 10, int MaxSpawn = 30, float Radius = 100, bool AlwaysSpawn =false,int RotMode = 1, float ScaleBasis = 0.2);
	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void PlacePawns(TSubclassOf<APawn> ToSpawn, int MinSpawn = 10, int MaxSpawn = 30, float Radius = 100, bool AlwaysSpawn = true, int RotMode = 1, float ScaleBasis = 0.0);
	UFUNCTION(BlueprintCallable, Category = "Pool")
	 void SetPool(UMyPool* inPool, FVector location);
	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	FVector NavigationBoundsOffset;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
		void PositionNavMeshBoundsVolume(FVector location);
		float MyAddRotation = 0.f;
		bool CanSpawn(FVector Location, float Radius);
		UMyPool* Pool;
		AActor* NavMeshBoundsVolume;
		
};
