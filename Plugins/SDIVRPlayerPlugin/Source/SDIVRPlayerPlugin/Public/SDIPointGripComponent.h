#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "ESDIVRControllerType.h"
#include "ESDIHandPose.h"
#include "SDIGripComponentInterface.h"
#include "SDIHandPoseInfo.h"
#include "InputCoreTypes.h"
#include "ESDIGripType.h"
#include "ESDIGripMovementTarget.h"
#include "ESDIGripMovement.h"
#include "UObject/NoExportTypes.h"
#include "SDIRemapGripRotationSettings.h"
#include "SDIGripInfo.h"
#include "SDIPIDControllerSettings.h"
#include "SDIComponentReplacement.h"
#include "SDIPointGripComponent.generated.h"

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIPointGripComponent : public UPrimitiveComponent, public ISDIGripComponentInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    EControllerHand hand;
    
    UPROPERTY(EditAnywhere)
    ESDIHandPose HandPose;
    
    UPROPERTY(EditAnywhere)
    FSDIHandPoseInfo HandPoseInfo;
    
    UPROPERTY(EditAnywhere)
    ESDIGripType GripType;
    
    UPROPERTY(EditAnywhere)
    FName ConstraintPivotSocket;
    
    UPROPERTY(EditAnywhere)
    ESDIGripMovement RotationGripMovement;
    
    UPROPERTY(EditAnywhere)
    ESDIGripMovementTarget RotationGripMovementTarget;
    
    UPROPERTY(EditAnywhere)
    FSDIRemapGripRotationSettings RotationGripMovementRemapSettings;
    
    UPROPERTY(EditAnywhere)
    bool bUseTrackedHandForConstraintAdjustments;
    
    UPROPERTY(EditAnywhere)
    bool bApplyRotationConstraintsOnGrab;
    
    UPROPERTY(EditAnywhere)
    bool bApplyRotationConstraintsOnGrabTwist;
    
    UPROPERTY(EditAnywhere)
    bool bApplyRotationConstraintsOnGrabSwing1;
    
    UPROPERTY(EditAnywhere)
    bool bApplyRotationConstraintsOnGrabSwing2;
    
    UPROPERTY(EditAnywhere)
    FSDIGripInfo GripOffset;
    
    UPROPERTY(EditAnywhere)
    bool bPreferredForGrabFromInventory;
    
    UPROPERTY(EditAnywhere)
    bool bPreferredForRangedGrab;
    
    UPROPERTY(EditAnywhere)
    bool bPreferredForNonVR;
    
    UPROPERTY(EditAnywhere)
    bool bMaintainAttachment;
    
    UPROPERTY(EditAnywhere)
    FTransform HandRelativeOffset;
    
    UPROPERTY(EditAnywhere)
    TMap<ESDIVRControllerType, FTransform> SingleHandedRelativeOffsetPerController;
    
    UPROPERTY(EditAnywhere)
    TMap<ESDIVRControllerType, FTransform> TwoHandedRelativeOffsetPerController;
    
    UPROPERTY(EditAnywhere)
    float LinearDistanceUpdateThreshold;
    
    UPROPERTY(EditAnywhere)
    float AngularDistanceUpdateThresholdDegrees;
    
    UPROPERTY(EditDefaultsOnly)
    bool bOverrideSinglePhysicsHandLocationPID;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIPIDControllerSettings SinglePhysicsHandLocationPID;
    
    UPROPERTY(EditDefaultsOnly)
    float SinglePhysicsHandLocationPIDScalar;
    
    UPROPERTY(EditDefaultsOnly)
    bool bOverrideSinglePhysicsHandRotationPID;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIPIDControllerSettings SinglePhysicsHandRotationPID;
    
    UPROPERTY(EditDefaultsOnly)
    float SinglePhysicsHandRotationPIDScalar;
    
    UPROPERTY(EditDefaultsOnly)
    bool bOverrideDualPhysicsHandLocationPID;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIPIDControllerSettings DualPhysicsHandLocationPID;
    
    UPROPERTY(EditDefaultsOnly)
    float DualPhysicsHandLocationPIDScalar;
    
    UPROPERTY(EditDefaultsOnly)
    bool bOverrideDualPhysicsHandRotationPID;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIPIDControllerSettings DualPhysicsHandRotationPID;
    
    UPROPERTY(EditDefaultsOnly)
    float DualPhysicsHandRotationPIDScalar;
    
    UPROPERTY(Transient)
    FSDIComponentReplacement ComponentReplacement;
    
public:
    USDIPointGripComponent();
    
    // Fix for true pure virtual functions not being implemented
};

