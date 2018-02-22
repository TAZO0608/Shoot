// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPool.h"
#include "MyPros.generated.h"

UCLASS()
class SHOOT_API AMyPros : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPros();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn = 10, int MaxSpawn = 30, float Radius = 100, bool AlwaysSpawn =false,int RotMode = 1, float ScaleBasis = 0.2);
	UFUNCTION(BlueprintCallable, Category = "Pool")
	 void SetPool(UMyPool* inPool);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
		float MyAddRotation = 0.f;
		bool CanSpawn(FVector Location, float Radius);
		UMyPool* Pool;
	
};
