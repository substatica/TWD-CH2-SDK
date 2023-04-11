#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDISkinReplicationDataCustomization.generated.h"

class USDISkinObject;

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDISkinReplicationDataCustomization {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    TSubclassOf<USDISkinObject> SkinRef;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<uint8> Data;
    
    FSDISkinReplicationDataCustomization();
};

