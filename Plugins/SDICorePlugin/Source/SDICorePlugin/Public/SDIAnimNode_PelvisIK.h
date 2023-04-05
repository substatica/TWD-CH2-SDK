#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDIAnimNode_SkeletalControlBase.h"
#include "BoneContainer.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "RVector.h"
#include "SDIAnimNode_PelvisIK.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAnimNode_PelvisIK : public FSDIAnimNode_SkeletalControlBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FBoneReference PelvisBone;
    
    UPROPERTY(EditAnywhere)
    FBoneReference LeftThighBone;
    
    UPROPERTY(EditAnywhere)
    FBoneReference LeftCalfBone;
    
    UPROPERTY(EditAnywhere)
    FBoneReference LeftFootBone;
    
    UPROPERTY(EditAnywhere)
    FBoneReference RightThighBone;
    
    UPROPERTY(EditAnywhere)
    FBoneReference RightCalfBone;
    
    UPROPERTY(EditAnywhere)
    FBoneReference RightFootBone;
    
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator EffectorLocationSpring;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ERelativeTransformSpace> EffectorLocationSpace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector EffectorLocation;
    
    UPROPERTY(EditAnywhere)
    float StretchAmount;
    
    UPROPERTY(EditAnywhere)
    FRVector PelvisMotionRange;
    
    UPROPERTY(EditAnywhere)
    FVector PelvisMotionRangeOffset;
    
    UPROPERTY(EditAnywhere)
    float PelvisMotionRangeSphericalWeight;
    
protected:
    UPROPERTY(Transient)
    bool bPelvisIsValidToEvaluate;
    
    UPROPERTY(Transient)
    bool bLeftLegIsValidToEvaluate;
    
    UPROPERTY(Transient)
    bool bRightLegIsValidToEvaluate;
    
public:
    FSDIAnimNode_PelvisIK();
};

