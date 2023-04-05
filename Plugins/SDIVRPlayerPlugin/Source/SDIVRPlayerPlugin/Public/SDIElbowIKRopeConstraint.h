#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIElbowIKRopeConstraint.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIElbowIKRopeConstraint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector HandPivot;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector EndPivot;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsOtherHand;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bEndPivotIsOtherHand;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsTaut;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TautTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TautLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TautPct;
    
    FSDIElbowIKRopeConstraint();
};

