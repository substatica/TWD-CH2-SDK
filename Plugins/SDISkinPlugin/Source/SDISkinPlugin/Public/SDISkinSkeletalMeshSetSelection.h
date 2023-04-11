#pragma once
#include "CoreMinimal.h"
#include "SDISkinSelection.h"
#include "SDISkinParamSelections.h"
#include "SDISkinSkeletalMeshSetSelection.generated.h"

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDISkinSkeletalMeshSetSelection : public FSDISkinSelection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    FSDISkinParamSelections ParamInfo;
    
    FSDISkinSkeletalMeshSetSelection();
};

