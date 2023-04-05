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
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UDataTable* AverageSpawnTable;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UDataTable* RareSpawnTable;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    bool bRare;
    
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSubclassOf<UTWDCharacterSkin> SkinOverride;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UAnimSequence* PoseOverride;
    
    ATWDNightModeLootSpawner(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintPure)
    ATWDNightModeLootSpawnerNetwork* GetSpawnNetwork() const;
    
};

