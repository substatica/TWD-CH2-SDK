#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIActorSpawnerVolume.h"
#include "TWDNightModeLootSpawner.generated.h"

class UDataTable;
class UTWDCharacterSkin;
class UAnimSequence;
class ATWDNightModeLootSpawnerNetwork;

UCLASS()
class TWD_API ATWDNightModeLootSpawner : public ASDIActorSpawnerVolume {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UDataTable* AverageSpawnTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UDataTable* RareSpawnTable;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    bool bRare;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<UTWDCharacterSkin> SkinOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAnimSequence* PoseOverride;
    
    ATWDNightModeLootSpawner(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintPure)
    ATWDNightModeLootSpawnerNetwork* GetSpawnNetwork() const;
    
};

