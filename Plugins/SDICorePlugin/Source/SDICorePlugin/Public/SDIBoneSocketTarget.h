#pragma once
#include "CoreMinimal.h"
#include "BoneContainer.h"
#include "SDISocketReference.h"
#include "SDIBoneSocketTarget.generated.h"

USTRUCT(BlueprintType)
struct FSDIBoneSocketTarget {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    bool bUseSocket;
    
    UPROPERTY(EditAnywhere)
    FBoneReference BoneReference;
    
    UPROPERTY(EditAnywhere)
    FSDISocketReference SocketReference;
    
    SDICOREPLUGIN_API FSDIBoneSocketTarget();
};

