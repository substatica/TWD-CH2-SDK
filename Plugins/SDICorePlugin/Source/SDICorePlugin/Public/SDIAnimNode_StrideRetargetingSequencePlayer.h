#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNode_SequencePlayer.h"
#include "BoneContainer.h"
#include "SDIFootPrediction.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIAnimNode_StrideRetargetingSequencePlayer.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAnimNode_StrideRetargetingSequencePlayer : public FAnimNode_SequencePlayer {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FBoneReference LeftFootBoneToModify;
    
    UPROPERTY(EditAnywhere)
    FBoneReference RightFootBoneToModify;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIFootPrediction LeftFootPredictionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIFootPrediction RightFootPredictionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bWarpRot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SourceAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DestAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bWarpLoc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SourceDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DestDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTransform StartingTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector TranslationOffsetScale;
    
    UPROPERTY(Transient)
    float TotalTime;
    
    UPROPERTY(Transient)
    FTransform ComponentTransform;
    
    UPROPERTY(Transient)
    FTransform InverseComponentTransform;
    
    UPROPERTY(Transient)
    FTransform ActorTransform;
    
    FSDIAnimNode_StrideRetargetingSequencePlayer();
};

