#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIThrusterEntry.generated.h"

class UPrimitiveComponent;
class UCurveBase;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIThrusterEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> Component;
    
    UPROPERTY(Transient)
    FName BodyName;
    
    UPROPERTY(Transient)
    FTransform Transform;
    
    UPROPERTY(Transient)
    bool bAttached;
    
    UPROPERTY(Transient)
    bool bAccelChange;
    
    UPROPERTY(Transient)
    float Force;
    
    UPROPERTY(Transient)
    UCurveBase* ForceCurve;
    
    UPROPERTY(Transient)
    float Duration;
    
    UPROPERTY(Transient)
    int32 LoopCount;
    
    UPROPERTY(Transient)
    float CurrentTime;
    
    FSDIThrusterEntry();
};

