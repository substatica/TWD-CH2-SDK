#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIWeaponHitEntry.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIWeaponHitEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UPrimitiveComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<FName> BoneNames;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform Transform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform PrevTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Lerp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FString TraceString;
    
    FSDIWeaponHitEntry();
};

