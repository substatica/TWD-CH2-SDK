#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TWDSpawnControlVolume.generated.h"

class UShapeComponent;
class ASDIActorSpawner;

UCLASS()
class TWD_API ATWDSpawnControlVolume : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDisableOnLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FName> ControlledTags;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Instanced)
    UShapeComponent* Volume;
    
    UPROPERTY()
    TArray<ASDIActorSpawner*> ControlledSpawners;
    
    UPROPERTY()
    TArray<bool> CachedEnabledStates;
    
    UPROPERTY()
    bool bEnabled;
    
public:
    ATWDSpawnControlVolume();
    UFUNCTION(BlueprintCallable)
    void RevertLastCommand();
    
    UFUNCTION(BlueprintCallable)
    void GatherAllSpawners();
    
    UFUNCTION(BlueprintCallable)
    void DisableAllSpawners();
    
};

