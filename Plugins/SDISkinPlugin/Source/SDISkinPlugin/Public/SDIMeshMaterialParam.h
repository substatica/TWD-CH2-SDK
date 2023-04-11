#pragma once
#include "CoreMinimal.h"
#include "ESDIMeshMaterialParamType.h"
#include "UObject/NoExportTypes.h"
#include "SDIMeshMaterialParam.generated.h"

class UMaterialInterface;
class UTexture;

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDIMeshMaterialParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    ESDIMeshMaterialParamType Type;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 Index;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FName Param;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FLinearColor Value;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UTexture* Texture;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UMaterialInterface* Material;
    
    FSDIMeshMaterialParam();
};

