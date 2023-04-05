#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "eCustomMovement.h"
#include "SDITransform_NetQuantize.h"
#include "SDICablePivot.h"
#include "Engine/NetSerialization.h"
#include "SavedMove_SDICharacterAdvanced_MoveData.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSavedMove_SDICharacterAdvanced_MoveData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly)
    TEnumAsByte<EMovementMode> MovementMode;
    
    UPROPERTY(BlueprintReadOnly)
    TEnumAsByte<eCustomMovement::Type> CustomMovementMode;
    
    UPROPERTY(BlueprintReadOnly)
    FSDITransform_NetQuantize LeftHandTrackedTransform;
    
    UPROPERTY(BlueprintReadOnly)
    FSDITransform_NetQuantize LeftHandTransform;
    
    UPROPERTY(BlueprintReadOnly)
    FVector_NetQuantize10 LeftHandVelocity;
    
    UPROPERTY(BlueprintReadOnly)
    FHitResult LeftHandGrip;
    
    UPROPERTY(BlueprintReadOnly)
    bool bLeftHandClimbing;
    
    UPROPERTY(BlueprintReadOnly)
    bool bLeftHandValid;
    
    UPROPERTY(BlueprintReadOnly)
    FSDITransform_NetQuantize RightHandTrackedTransform;
    
    UPROPERTY(BlueprintReadOnly)
    FSDITransform_NetQuantize RightHandTransform;
    
    UPROPERTY(BlueprintReadOnly)
    FVector_NetQuantize10 RightHandVelocity;
    
    UPROPERTY(BlueprintReadOnly)
    FHitResult RightHandGrip;
    
    UPROPERTY(BlueprintReadOnly)
    bool bRightHandClimbing;
    
    UPROPERTY(BlueprintReadOnly)
    bool bRightHandValid;
    
    UPROPERTY(BlueprintReadOnly)
    FHitResult MantleTargetInfo;
    
    UPROPERTY(BlueprintReadOnly)
    bool bMantleOver;
    
    UPROPERTY(BlueprintReadOnly)
    bool bMantleRequireCrouch;
    
    UPROPERTY(BlueprintReadOnly)
    FVector_NetQuantize100 HMDMovementDelta;
    
    UPROPERTY(BlueprintReadOnly)
    TArray<FSDICablePivot> RopePivots;
    
    FSavedMove_SDICharacterAdvanced_MoveData();
};

