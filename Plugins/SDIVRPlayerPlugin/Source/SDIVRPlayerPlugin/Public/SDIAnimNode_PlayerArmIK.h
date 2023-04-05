#pragma once
#include "CoreMinimal.h"
#include "SDIAnimNode_BaseArmIK.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIElbowIK.h"
#include "SDIAnimNode_PlayerArmIK.generated.h"

class UCurveFloat;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIAnimNode_PlayerArmIK : public FSDIAnimNode_BaseArmIK {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    UCurveFloat* ExtensionScaleCurve;
    
    UPROPERTY(EditAnywhere)
    UCurveFloat* ExtensionShoulderOffsetCurve;
    
    UPROPERTY(EditAnywhere)
    bool bUseNewElbowIK;
    
    UPROPERTY(EditAnywhere)
    FVectorRK4SpringInterpolator ElbowSpring;
    
    UPROPERTY(EditAnywhere)
    float ElbowSideRotationDefaultDeg;
    
    UPROPERTY(EditAnywhere)
    float ElbowSideRotationMaxDeg;
    
    UPROPERTY(EditAnywhere)
    float ElbowSideRotationSideContribution;
    
    UPROPERTY(EditAnywhere)
    float ElbowSideRotationSideExp;
    
    UPROPERTY(EditAnywhere)
    float ElbowSideRotationUpContribution;
    
    UPROPERTY(EditAnywhere)
    float ElbowSideRotationUpExp;
    
    UPROPERTY(EditAnywhere)
    float ElbowSideRotationForwardContribution;
    
    UPROPERTY(EditAnywhere)
    float ElbowSideRotationForwardExp;
    
    UPROPERTY(EditAnywhere)
    float ElbowSideRotationForwardDownExp;
    
    UPROPERTY(EditAnywhere)
    float ElbowSideRotationPalmUpExp;
    
protected:
    UPROPERTY(Transient)
    FVector ArmMeshScale;
    
    UPROPERTY(Transient)
    FSDIElbowIK HandElbowIK;
    
    UPROPERTY(Transient)
    FSDIElbowIK OtherHandElbowIK;
    
public:
    FSDIAnimNode_PlayerArmIK();
};

