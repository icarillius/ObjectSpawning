// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorToSpawn.h"
#include "MyObjectSpawner.generated.h"

UCLASS()
class OBJECTSPAWNING_API AMyObjectSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyObjectSpawner();
	
	// Creates the actor subclass
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<AMyActorToSpawn> ActorToSpawn;

	//Creates the function to spawn the object. 
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnObjAtLocation();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
