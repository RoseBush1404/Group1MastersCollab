// Developed By Group 1 of Master's Collab 2019-2020 at Staffordshire University


#include "SpinableTileSpawnPoint.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

USpinableTileSpawnPoint::USpinableTileSpawnPoint()
{
	PrimaryComponentTick.bCanEverTick = false;
}

AActor* USpinableTileSpawnPoint::GetSpanwedActor() const
{
	if (!SpawnedActor) { return nullptr; }
	return SpawnedActor;
}

void USpinableTileSpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	//Spawn the choosen class in and set up attachment
	SpawnedActor = GetWorld()->SpawnActorDeferred<AActor>(SpawnClass, GetComponentTransform());
	if (!SpawnedActor) { return; }
	SpawnedActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	UGameplayStatics::FinishSpawningActor(SpawnedActor, GetComponentTransform());


	//hide the template mesh of this class
	SetHiddenInGame(true, false);
	SetVisibility(false, false);
}

void USpinableTileSpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}