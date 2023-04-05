#pragma once
#include "CoreMinimal.h"
#include "SDIAnimNode_PlayerArmIK.h"
#include "UObject/NoExportTypes.h"
#include "SDIAnimNode_FirstPersonArmIK.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIAnimNode_FirstPersonArmIK : public FSDIAnimNode_PlayerArmIK {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    bool bMirroredBoneAxes;
    
    UPROPERTY(Transient)
    FTransform ShoulderTransform;
    
public:
    FSDIAnimNode_FirstPersonArmIK();
};

