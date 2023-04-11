#pragma once
#include "CoreMinimal.h"
#include "SDIRandomSkinTextureParam.generated.h"

class UTexture;

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDIRandomSkinTextureParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName Param;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<TSoftObjectPtr<UTexture>> Values;
    
    FSDIRandomSkinTextureParam();
};

