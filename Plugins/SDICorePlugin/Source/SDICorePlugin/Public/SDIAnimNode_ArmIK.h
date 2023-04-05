#pragma once
#include "CoreMinimal.h"
#include "SDIAnimNode_BaseArmIK.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "SDIAnimNode_ArmIK.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIAnimNode_ArmIK : public FSDIAnimNode_BaseArmIK {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    bool bRightHand;
    
    UPROPERTY(EditDefaultsOnly)
    FName HandCenterSocket;
    
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator EffectorLocationSpring;
    
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator EffectorRotationSpring;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ERelativeTransformSpace> EffectorTransformSpace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTransform EffectorTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bEnableEffectorSpring;
    
    UPROPERTY(Transient)
    FVector RelativeHandCenterOffset;
    
public:
    FSDIAnimNode_ArmIK();
};

