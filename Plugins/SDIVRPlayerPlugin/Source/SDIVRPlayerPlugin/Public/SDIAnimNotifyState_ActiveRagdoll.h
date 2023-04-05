#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "SDIAnimNotifyState_ActiveRagdoll.generated.h"

UCLASS(CollapseCategories, EditInlineNew)
class USDIAnimNotifyState_ActiveRagdoll : public UAnimNotifyState {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    FName PhysicalAnimationDataProfile;
    
    UPROPERTY(EditAnywhere)
    bool bTurnOn;
    
    UPROPERTY(EditAnywhere)
    bool bAllowBlendOut;
    
public:
    USDIAnimNotifyState_ActiveRagdoll();
};

