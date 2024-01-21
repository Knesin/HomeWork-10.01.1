// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocationCpp = GetActorLocation();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACppBaseActor::SinMovement()
{
	FVector TempLocation = InitialLocationCpp;
	TempLocation.Z = InitialLocationCpp.Z + AmplitudeCpp * FMath::Sin(FrequencyCpp * GetGameTimeSinceCreation());
	SetActorLocation(TempLocation);
	//UE_LOG(LogTemp, Display, TEXT("sin: %f"), FMath::Sin(FrequencyCpp * GetGameTimeSinceCreation()));
	//UE_LOG(LogTemp, Display, TEXT("Z: %f"), AmplitudeCpp * FMath::Sin(FrequencyCpp * GetGameTimeSinceCreation()));
}
