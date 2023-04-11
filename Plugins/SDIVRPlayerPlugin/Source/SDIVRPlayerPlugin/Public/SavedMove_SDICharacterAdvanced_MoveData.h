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
    UPROPERTY(BlueprintReadWrite)
    TEnumAsByte<EMovementMode> MovementMode;
    
    UPROPERTY(BlueprintReadWrite)
    TEnumAsByte<eCustomMovement::Type> CustomMovementMode;
    
    UPROPERTY(BlueprintReadWrite)
    FSDITransform_NetQuantize LeftHandTrackedTransform;
    
    UPROPERTY(BlueprintReadWrite)
    FSDITransform_NetQuantize LeftHandTransform;
    
    UPROPERTY(BlueprintReadWrite)
    FVector_NetQuantize10 LeftHandVelocity;
    
    UPROPERTY(BlueprintReadWrite)
    FHitResult LeftHandGrip;
    
    UPROPERTY(BlueprintReadWrite)
    bool bLeftHandClimbing;
    
    UPROPERTY(BlueprintReadWrite)
    bool bLeftHandValid;
    
    UPROPERTY(BlueprintReadWrite)
    FSDITransform_NetQuantize RightHandTrackedTransform;
    
    UPROPERTY(BlueprintReadWrite)
    FSDITransform_NetQuantize RightHandTransform;
    
    UPROPERTY(BlueprintReadWrite)
    FVector_NetQuantize10 RightHandVelocity;
    
    UPROPERTY(BlueprintReadWrite)
    FHitResult RightHandGrip;
    
    UPROPERTY(BlueprintReadWrite)
    bool bRightHandClimbing;
    
    UPROPERTY(BlueprintReadWrite)
    bool bRightHandValid;
    
    UPROPERTY(BlueprintReadWrite)
    FHitResult MantleTargetInfo;
    
    UPROPERTY(BlueprintReadWrite)
    bool bMantleOver;
    
    UPROPERTY(BlueprintReadWrite)
    bool bMantleRequireCrouch;
    
    UPROPERTY(BlueprintReadWrite)
    FVector_NetQuantize100 HMDMovementDelta;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FSDICablePivot> RopePivots;
    
    FSavedMove_SDICharacterAdvanced_MoveData();
};

