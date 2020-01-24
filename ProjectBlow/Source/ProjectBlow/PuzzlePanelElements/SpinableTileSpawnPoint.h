// Developed By Group 1 of Master's Collab 2019-2020 at Staffordshire University

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "SpinableTileSpawnPoint.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (PuzzlePanelElements), meta = (BlueprintSpawnableComponent))
class PROJECTBLOW_API USpinableTileSpawnPoint : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	USpinableTileSpawnPoint();

	UFUNCTION(BlueprintCallable, Category = Getters)
	AActor* GetSpanwedActor() const;

	UFUNCTION(BlueprintCallable, Category = Getters)
		bool GetIsWinCondition() { return IsWinCondition; };

protected:

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AActor> SpawnClass;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		bool IsWinCondition;

	UPROPERTY()
		AActor* SpawnedActor = nullptr;
};
