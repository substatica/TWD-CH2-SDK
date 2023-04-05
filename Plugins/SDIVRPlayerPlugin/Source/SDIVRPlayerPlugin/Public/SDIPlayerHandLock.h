#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIHandPoseInfo.h"
#include "SDIGripInfo.h"
#include "SDIPlayerHandLock.generated.h"

class UObject;
class USceneComponent;
class UActorComponent;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIPlayerHandLock {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDebugRender;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<UObject> LockOwner;
    
    UPROPERTY(Transient)
    bool bLockLocation;
    
    UPROPERTY(Transient)
    bool bResetLocationSpring;
    
    UPROPERTY(Transient)
    FVectorRK4SpringInterpolator LocationSpring;
    
    UPROPERTY(Transient)
    FTransform LocationTransform;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USceneComponent> LocationParent;
    
    UPROPERTY(Transient)
    FName LocationParentSocketName;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USceneComponent> LocationRef;
    
    UPROPERTY(Transient)
    FName LocationRefSocketName;
    
    UPROPERTY(Transient)
    FTransform LastLocationParentTransform;
    
    UPROPERTY(Transient)
    float LocationArmLengthReleaseFactor;
    
    UPROPERTY(Transient)
    float LocationExceedingArmLengthReleaseFactorTime;
    
    UPROPERTY(Transient)
    bool bIgnoreCollisionsWithOtherHand;
    
    UPROPERTY(Transient)
    bool bLockRotation;
    
    UPROPERTY(Transient)
    FRotator Rotation;
    
    UPROPERTY(Transient)
    FRotator RotationExtent;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USceneComponent> RotationParent;
    
    UPROPERTY(Transient)
    FName RotationParentSocketName;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USceneComponent> RotationRef;
    
    UPROPERTY(Transient)
    FName RotationRefSocketName;
    
    UPROPERTY(Transient)
    FTransform LastRotationParentTransform;
    
    UPROPERTY(Transient)
    FTransform LastLimitedLocationParentTransform;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<USceneComponent> LastLimitedLocationParent;
    
    UPROPERTY(Transient)
    FName LastLimitedLocationParentSocketName;
    
    UPROPERTY(Transient)
    FVector LastLimitedLocationRel;
    
    UPROPERTY(Transient)
    FVector LastLimitedLocationRelLerp;
    
    UPROPERTY(Transient)
    float LocationLimitLerp;
    
    UPROPERTY(Transient)
    bool bLocationLimitLerpReset;
    
    UPROPERTY(Transient)
    FQuat LastLimitedRotation;
    
    UPROPERTY(Transient)
    FQuat LastLimitedRotationLerp;
    
    UPROPERTY(Transient)
    float RotationLimitLerp;
    
    UPROPERTY(Transient)
    bool bRotationLimitLerpReset;
    
    UPROPERTY(Transient)
    FSDIHandPoseInfo LockHandPose;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<UActorComponent> LockGripComponent;
    
    UPROPERTY(Transient)
    FSDIGripInfo LockGripInfo;
    
    UPROPERTY(Transient)
    bool bLockGripCollisionIgnored;
    
public:
    FSDIPlayerHandLock();
};

