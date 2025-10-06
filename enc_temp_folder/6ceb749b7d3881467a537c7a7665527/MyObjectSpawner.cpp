// Fill out your copyright notice in the Description page of Project Settings.


#include "MyObjectSpawner.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"

// Sets default values
AMyObjectSpawner::AMyObjectSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyObjectSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	SpawnVolume->SetupAttachment(RootComponent);


}

void AMyObjectSpawner::SpawnActor()
{
    if (GetWorld())
    {
        FVector SpawnLocation = GetActorLocation();
        FRotator SpawnRotation = GetActorRotation();

        AMyObjectSpawner* SpawnedActor = GetWorld()->SpawnActor<AMyObjectSpawner>(AMyObjectSpawner::StaticClass(), SpawnLocation, SpawnRotation);
        if (SpawnedActor)
        {
            UE_LOG(LogTemp, Log, TEXT("Spawned actor at %s"), *SpawnLocation.ToString());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to spawn actor"));
        }
    }
}

// Called every frame
void AMyObjectSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

