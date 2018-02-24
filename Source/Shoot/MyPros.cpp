// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPros.h"
#include "DrawDebugHelpers.h"


// Sets default values
AMyPros::AMyPros()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	NavigationBoundsOffset = FVector(2000, 0, 0);
}

// Called when the game starts or when spawned
void AMyPros::BeginPlay()
{
	Super::BeginPlay();

	
}
void AMyPros::SetPool(UMyPool* inPool, FVector location)
{
	if (inPool == nullptr) { return; }
	UE_LOG(LogTemp, Warning, TEXT("[%s] Setting Pool %s"), *(this->GetName()), *(inPool->GetName()));
	Pool = inPool;
	PositionNavMeshBoundsVolume(location);
}
void AMyPros::PlaceActors(TSubclassOf<AActor> ToSpawn, bool isPawn, int MinSpawn, int MaxSpawn, float Radius, bool AlwaysSpawn,int RotMode, float ScaleBasis)
{
	FVector Min(0, -2000, 0);
	FVector Max(4000, 2000, 0);
	FBox Bounds(Min, Max);
	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (size_t i = 0; i < NumberToSpawn; i++)
		 {
		FVector SpawnPoint = FMath::RandPointInBox(Bounds);
		float RandomScale = FMath::RandRange((1.f - ScaleBasis), (1.f + ScaleBasis));
		//UE_LOG(LogTemp, Warning, TEXT("SpawnPoint: %s"), *SpawnPoint.ToCompactString())
		if (AlwaysSpawn) {
			AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
			Spawned->SetActorRelativeLocation(SpawnPoint);
			Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
			if (RotMode == 1) 
			{
				float RandomRotation = FMath::RandRange(-180.f, 180.f);
				Spawned->SetActorRotation(FRotator(0, RandomRotation, 0));
			}
			else if (RotMode == 2)
			{
				 MyAddRotation += 90.f;
				 Spawned->SetActorRotation(FRotator(0, MyAddRotation, 0));
				
			}
			Spawned->SetActorScale3D(FVector(RandomScale));
			//if (isPawn) { Spawned->Tags.Add(FName("Enemy")); }
			
		}
		else if(CanSpawn(SpawnPoint, (Radius*RandomScale)))
		{
			AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
			Spawned->SetActorRelativeLocation(SpawnPoint);
			Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
			if (RotMode == 1)
			{
				float RandomRotation = FMath::RandRange(-180.f, 180.f);
				Spawned->SetActorRotation(FRotator(0, RandomRotation, 0));
			}
			else if (RotMode == 2)
			{
				MyAddRotation += 90.f;
				Spawned->SetActorRotation(FRotator(0, MyAddRotation, 0));
			}
			Spawned->SetActorScale3D(FVector(RandomScale));
			//if (isPawn) { Spawned->Tags.Add(FName("Enemy")); }
		}
		
			 }
	
}

void AMyPros::PlacePawns(TSubclassOf<APawn> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, bool AlwaysSpawn, int RotMode, float ScaleBasis)
{
	FVector Min(0, -2000, 0);
	FVector Max(4000, 2000, 0);
	FBox Bounds(Min, Max);
	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (size_t i = 0; i < NumberToSpawn; i++)
	{
		FVector SpawnPoint = FMath::RandPointInBox(Bounds);
		float RandomScale = FMath::RandRange((1.f - ScaleBasis), (1.f + ScaleBasis));
		//UE_LOG(LogTemp, Warning, TEXT("SpawnPoint: %s"), *SpawnPoint.ToCompactString())
		if (AlwaysSpawn) {
			APawn* Spawned = GetWorld()->SpawnActor<APawn>(ToSpawn);
			Spawned->SetActorRelativeLocation(SpawnPoint);
			Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
			if (RotMode == 1)
			{
				float RandomRotation = FMath::RandRange(-180.f, 180.f);
				Spawned->SetActorRotation(FRotator(0, RandomRotation, 0));
			}
			else if (RotMode == 2)
			{
				MyAddRotation += 90.f;
				Spawned->SetActorRotation(FRotator(0, MyAddRotation, 0));

			}
			Spawned->SetActorScale3D(FVector(RandomScale));
			Spawned->SpawnDefaultController();
			Spawned->Tags.Add(FName("Enemy"));

		}
		else if (CanSpawn(SpawnPoint, (Radius*RandomScale)))
		{
			APawn* Spawned = GetWorld()->SpawnActor<APawn>(ToSpawn);
			Spawned->SetActorRelativeLocation(SpawnPoint);
			Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
			if (RotMode == 1)
			{
				float RandomRotation = FMath::RandRange(-180.f, 180.f);
				Spawned->SetActorRotation(FRotator(0, RandomRotation, 0));
			}
			else if (RotMode == 2)
			{
				MyAddRotation += 90.f;
				Spawned->SetActorRotation(FRotator(0, MyAddRotation, 0));
			}
			Spawned->SetActorScale3D(FVector(RandomScale));
			Spawned->SpawnDefaultController();
			Spawned->Tags.Add(FName("Enemy"));
		}
		
	}

}
// Called every frame
void AMyPros::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
bool AMyPros::CanSpawn(FVector Location, float Radius)
{
	FHitResult HitResult;
	FVector G_Location =ActorToWorld().TransformPosition(Location) ;
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		G_Location,
		G_Location,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius)
		 );
	//FColor ResultColor = HasHit ? FColor::Red : FColor::Green;
	//DrawDebugSphere(GetWorld(), G_Location, Radius, 8, ResultColor, true, 100);
	return !HasHit;
}
void AMyPros::EndPlay(const EEndPlayReason::Type EndPlayReason)
 {
	Pool->Return(NavMeshBoundsVolume);
	}
void AMyPros::PositionNavMeshBoundsVolume(FVector location)
 {
	NavMeshBoundsVolume = Pool->Checkout();
	if (NavMeshBoundsVolume == nullptr)
		 {
		UE_LOG(LogTemp, Warning, TEXT("[%s] Not enough actors in pool."), *GetName());
		return;
		}
	UE_LOG(LogTemp, Warning, TEXT("[%s] Checked out: {%s}"), *GetName(), *NavMeshBoundsVolume->GetName());
	UE_LOG(LogTemp, Warning, TEXT("[%s]"), *(location.ToString()));
	NavMeshBoundsVolume->SetActorLocation(location);
	GetWorld()->GetNavigationSystem()->Build();
	
}