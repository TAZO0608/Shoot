// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPool.h"


// Sets default values for this component's properties
UMyPool::UMyPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


AActor* UMyPool::Checkout()
 {
	if (Pool.Num() == 0)
		 {
		return nullptr;
		}
	return Pool.Pop();

	}

void UMyPool::Return(AActor* ActorToReturn)
{
	if (ActorToReturn == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("[%s] Returned null actor."), *GetName());
		return;
		
	}
	Add(ActorToReturn);
		}

void UMyPool::Add(AActor* ActorToAdd)
{
	if (ActorToAdd == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("[%s] Added null actor."), *GetName());
		return;
		
	}
	Pool.Push(ActorToAdd);
		}

