#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIActorSpawner.h"
#include "SDIActorSpawnerVolume.generated.h"

class UBoxComponent;

UCLASS()
class SDICOREPLUGIN_API ASDIActorSpawnerVolume : public ASDIActorSpawner {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Instanced)
    TArray<UBoxComponent*> SpawnerVolumes;
    
    UPROPERTY(Instanced, Transient)
    TArray<UBoxComponent*> ActiveSpawnerVolumes;
    
    UPROPERTY(Transient)
    int32 ActiveSpawnerVolumeIndex;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<ASDIActorSpawner> SpawnerModel;
    
public:
    ASDIActorSpawnerVolume(const FObjectInitializer& ObjectInitializer);
};

