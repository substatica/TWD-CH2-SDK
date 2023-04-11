#pragma once
#include "CoreMinimal.h"
#include "SDIRandomSkinParamSetEntry.h"
#include "UObject/Object.h"
#include "SDIRandomSkinParamSetShared.generated.h"

UCLASS(BlueprintType)
class SDISKINPLUGIN_API USDIRandomSkinParamSetShared : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDIRandomSkinParamSetEntry> Entries;
    
public:
    USDIRandomSkinParamSetShared();
};

