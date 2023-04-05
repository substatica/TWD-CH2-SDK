#pragma once
#include "CoreMinimal.h"
#include "SDIAxisControlCurve.h"
#include "BoneContainer.h"
#include "SDIAnimNode_ControlledBone.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAnimNode_ControlledBone {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FBoneReference Bone;
    
    UPROPERTY(EditAnywhere)
    FBoneReference ControlBone;
    
    UPROPERTY(EditAnywhere)
    FBoneReference ControlRelativeBone;
    
    UPROPERTY(EditAnywhere)
    TArray<FSDIAxisControlCurve> ControlCurves;
    
protected:
    UPROPERTY(Transient)
    bool bIsValidToEvaluate;
    
    UPROPERTY(Transient)
    bool bControlRelative;
    
public:
    FSDIAnimNode_ControlledBone();
};

