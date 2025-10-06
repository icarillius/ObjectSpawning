// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorToSpawn.h"

// Sets default values
AMyActorToSpawn::AMyActorToSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorToSpawn::BeginPlay()
{
	Super::BeginPlay();
	
	//Output to show the object exists
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("This Object Exists")));
	
}

// Called every frame
void AMyActorToSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

