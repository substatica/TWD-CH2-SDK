#pragma once
#include "CoreMinimal.h"
#include "TWDDismemberWoundInfo.h"
#include "TWDDismemberedLimb.generated.h"

class ATWDDismemberLimbCap;
class ATWDDismemberDroppedLimb;

USTRUCT(BlueprintType)
struct FTWDDismemberedLimb : public FTWDDismemberWoundInfo {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    float Timestamp;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ATWDDismemberLimbCap> LimbCap;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ATWDDismemberDroppedLimb> DroppedLimb;
    
    UPROPERTY(Transient)
    bool bIsAdvancedDismemberment;
    
public:
    TWD_API FTWDDismemberedLimb();
};

