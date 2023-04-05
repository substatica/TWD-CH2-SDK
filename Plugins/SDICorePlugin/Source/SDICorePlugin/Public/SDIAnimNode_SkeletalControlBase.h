#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "Animation/AnimNodeBase.h"
#include "Animation/InputScaleBias.h"
#include "UObject/NoExportTypes.h"
#include "SDIAnimNode_SkeletalControlBase.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAnimNode_SkeletalControlBase : public FAnimNode_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FPoseLink SourcePose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Alpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FInputScaleBias AlphaScaleBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIgnoreTimeDilation;
    
protected:
    UPROPERTY(Transient)
    float ActualAlpha;
    
    UPROPERTY(Transient)
    TArray<FTransform> LocalTransforms;
    
    UPROPERTY(Transient)
    int32 RootIndex;
    
    UPROPERTY(Transient)
    FTransform ComponentSpaceRootTransform;
    
    UPROPERTY(Transient)
    FTransform WorldSpaceRootTransform;
    
    UPROPERTY(Transient)
    float ActorCustomTimeDilation;
    
private:
    UPROPERTY(Transient)
    bool bIsRelevant;
    
public:
    FSDIAnimNode_SkeletalControlBase();
};

