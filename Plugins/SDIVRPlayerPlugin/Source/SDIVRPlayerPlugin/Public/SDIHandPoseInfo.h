#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ESDIHandPose.h"
#include "SDIHandPoseInfo.generated.h"

class USDIHandPoseAnimInstance;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIHandPoseInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ESDIHandPose HandPose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<USDIHandPoseAnimInstance> HandPoseAnimInstance;
    
    FSDIHandPoseInfo();
};

