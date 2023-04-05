#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "SDIAnimNotifyState_Ragdoll.generated.h"

UCLASS(CollapseCategories, EditInlineNew)
class USDIAnimNotifyState_Ragdoll : public UAnimNotifyState {
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
    
    UPROPERTY(EditAnywhere)
    bool bAttachToMeshRoot;
    
public:
    USDIAnimNotifyState_Ragdoll();
};

