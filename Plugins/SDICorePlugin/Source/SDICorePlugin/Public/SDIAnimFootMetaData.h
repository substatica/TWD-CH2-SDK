#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "SDISingleFootStrideData.h"
#include "SDIAnimFootMetaData.generated.h"

UCLASS(BlueprintType, CollapseCategories, EditInlineNew)
class SDICOREPLUGIN_API USDIAnimFootMetaData : public UAnimMetaData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDISingleFootStrideData LeftFoot;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FSDISingleFootStrideData RightFoot;
    
    USDIAnimFootMetaData();
};

