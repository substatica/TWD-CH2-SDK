#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "SDIAnimNotify_StartRagdoll.generated.h"

UCLASS(CollapseCategories)
class USDIAnimNotify_StartRagdoll : public UAnimNotify {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    bool bStartImmediately;
    
    UPROPERTY(EditAnywhere)
    FName OverrideConstraintProfileName;
    
    UPROPERTY(EditAnywhere)
    float OverrideConstraintProfileDuration;
    
    UPROPERTY(EditAnywhere)
    float PhysicalAnimationStrength;
    
    UPROPERTY(EditAnywhere)
    FName PhysicalAnimationProfileName;
    
    UPROPERTY(EditAnywhere)
    float PhysicalAnimationDuration;
    
public:
    USDIAnimNotify_StartRagdoll();
};

