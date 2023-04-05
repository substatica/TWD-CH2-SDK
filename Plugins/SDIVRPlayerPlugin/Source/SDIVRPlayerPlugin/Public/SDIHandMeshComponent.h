#pragma once
#include "CoreMinimal.h"
#include "SDIQuatPIDController.h"
#include "Components/SkeletalMeshComponent.h"
#include "SDIVectorPIDController.h"
#include "UObject/NoExportTypes.h"
#include "SDIBlendOption.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIHandMeshComponent.generated.h"

class USceneComponent;
class UCurveFloat;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIHandMeshComponent : public USkeletalMeshComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditDefaultsOnly)
    bool bUsePhysics;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIVectorPIDController LocationPIDController;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIQuatPIDController RotationPIDController;
    
    UPROPERTY(EditDefaultsOnly)
    UCurveFloat* RotationProportionalGainCurve;
    
    UPROPERTY(EditDefaultsOnly)
    UCurveFloat* RotationDerivativeGainCurve;
    
    UPROPERTY(EditDefaultsOnly)
    float SingleHandedRotationGainCurveMinMass;
    
    UPROPERTY(EditDefaultsOnly)
    float TwoHandedRotationGainCurveMinMass;
    
    UPROPERTY(EditDefaultsOnly)
    float TwoHandedGrabScalar;
    
    UPROPERTY(EditDefaultsOnly)
    float TwoHandedGrabRotationScalar;
    
    UPROPERTY(EditDefaultsOnly)
    float MinLimitedForceScale;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIBlendOption MinLimitedForceScaleBlend;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USceneComponent> DesiredRelativeComp;
    
    UPROPERTY(Transient)
    FTransform StartDesiredRelativeCompTransform;
    
    UPROPERTY(Transient)
    FTransform DesiredRelativeCompTransform;
    
    UPROPERTY(Transient)
    FVector RelativeDesiredLocation;
    
    UPROPERTY(Transient)
    FQuat RelativeDesiredRotation;
    
    UPROPERTY(Transient)
    float DesiredRelativeCompTransform_ElapsedTickTime;
    
    UPROPERTY(Transient)
    FQuat RootBoneQuat;
    
    UPROPERTY(Transient)
    FVector LimitForceDirection;
    
public:
    USDIHandMeshComponent();
};

