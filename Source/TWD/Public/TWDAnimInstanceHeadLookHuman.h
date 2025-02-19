#pragma once
#include "CoreMinimal.h"
#include "TWDAnimInstanceHeadLook.h"
#include "UObject/NoExportTypes.h"
#include "TWDAnimInstanceHeadLookHuman.generated.h"

UCLASS(NonTransient)
class TWD_API UTWDAnimInstanceHeadLookHuman : public UTWDAnimInstanceHeadLook {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float AngularVelocityScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float HeadLookExtent;
    
    UPROPERTY(Transient)
    float AngularVelocity;
    
    UPROPERTY(Transient)
    FQuat HeadLookRotation;
    
    UTWDAnimInstanceHeadLookHuman();
};

