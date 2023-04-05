#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "SDIAnimNotify_StopRagdoll.generated.h"

UCLASS(CollapseCategories)
class USDIAnimNotify_StopRagdoll : public UAnimNotify {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    bool bAttachToMeshRoot;
    
public:
    USDIAnimNotify_StopRagdoll();
};

