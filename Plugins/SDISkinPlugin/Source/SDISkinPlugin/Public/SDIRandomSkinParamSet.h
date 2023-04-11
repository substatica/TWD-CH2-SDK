#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIRandomSkinParamSetEntry.h"
#include "SDIRandomSkinParamSet.generated.h"

class USDIRandomSkinParamSetShared;

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDIRandomSkinParamSet {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FSDIRandomSkinParamSetEntry> Entries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<USDIRandomSkinParamSetShared> SharedParamSet;
    
public:
    FSDIRandomSkinParamSet();
};

