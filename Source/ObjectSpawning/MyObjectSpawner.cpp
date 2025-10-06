// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorToSpawn.h"
#include "MyObjectSpawner.h"


// Sets default values
AMyObjectSpawner::AMyObjectSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyObjectSpawner::SpawnObjAtLocation()
{
	if (ActorToSpawn)
	{
		FVector SpawnLocation = GetActorLocation();   // Get manager's position
		FRotator SpawnRotation = GetActorRotation();  // Get manager's rotation

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this; // Set owner if desired

		GetWorld()->SpawnActor<AMyActorToSpawn>(ActorToSpawn, SpawnLocation, SpawnRotation, SpawnParams);

		UE_LOG(LogTemp, Log, TEXT("Spawned object at manager's location."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SpawnObjectAtManagerLocation: ActorToSpawn not set!"));
	}
	
}

// Called when the game starts or when spawned
void AMyObjectSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnObjAtLocation();
}



// Called every frame
void AMyObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

