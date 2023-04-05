#pragma once
#include "CoreMinimal.h"
#include "SDIAnimNode_SkeletalControlBase.h"
#include "BoneContainer.h"
#include "SDIAnimNode_ArmIK_TwistBone.h"
#include "SDIAnimNode_ControlledBone.h"
#include "Engine/SpringInterpolator.h"
#include "RFloat.h"
#include "UObject/NoExportTypes.h"
#include "SDIAnimNode_BaseArmIK.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAnimNode_BaseArmIK : public FSDIAnimNode_SkeletalControlBase {
    GENERATED_BODY()
public:
    UPROPERTY(VisibleAnywhere)
    bool bShoulderIsBase;
    
    UPROPERTY(EditAnywhere)
    FBoneReference WristBone;
    
    UPROPERTY(EditAnywhere)
    FBoneReference ElbowBone;
    
    UPROPERTY(EditAnywhere)
    FBoneReference ShoulderBone;
    
    UPROPERTY(EditAnywhere)
    TArray<FSDIAnimNode_ArmIK_TwistBone> ForeArmTwistBones;
    
    UPROPERTY(EditAnywhere)
    bool bForeArmTwistBonesAreChained;
    
    UPROPERTY(EditAnywhere)
    float ForeArmTwistSwapThreshold;
    
    UPROPERTY(EditAnywhere)
    TArray<FSDIAnimNode_ArmIK_TwistBone> UpperArmTwistBones;
    
    UPROPERTY(EditAnywhere)
    bool bUpperArmTwistBonesAreChained;
    
    UPROPERTY(EditAnywhere)
    TArray<FSDIAnimNode_ControlledBone> ControlledBones;
    
    UPROPERTY(EditAnywhere)
    float MaxExtensionPct;
    
    UPROPERTY(EditAnywhere)
    float ComfortableElbowRotation;
    
    UPROPERTY(EditAnywhere)
    FRFloat ElbowRotationRange;
    
    UPROPERTY(EditAnywhere)
    float CalcElbowParallelBlendStart;
    
    UPROPERTY(EditAnywhere)
    float CalcElbowParallelBlendExp;

    UPROPERTY(EditAnywhere)
    FFloatRK4SpringInterpolator ElbowRotationSpring;

protected:
    UPROPERTY(Transient)
    float SideMultiplier;
    
    UPROPERTY(Transient)
    bool bInputsValid;
    
    UPROPERTY(Transient)
    float ElbowRotationSpringTarget;
    
    UPROPERTY(Transient)
    float LastForeArmTwistDelta;
    
    UPROPERTY(Transient)
    bool bIsValidToEvaluate;
    
public:
    FSDIAnimNode_BaseArmIK();
};

