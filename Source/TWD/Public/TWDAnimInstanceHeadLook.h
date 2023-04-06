#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "UObject/NoExportTypes.h"
#include "EAnimInstanceHeadLookCharacterType.h"
#include "UObject/NoExportTypes.h"
#include "TWDAnimInstanceHeadLook.generated.h"

class ACharacter;

UCLASS(NonTransient)
class TWD_API UTWDAnimInstanceHeadLook : public UAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EAnimInstanceHeadLookCharacterType CharacterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bIsHeadTracking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector LookAtTargetLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float HeadInterpolateSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float HeadLookAtLocationMaxPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float HeadLookAtLocationMinPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float HeadLookAtLocationMaxYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float HeadLookAtLocationMinYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LookAtAlpha_Head;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LookAtAlpha_Neck02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LookAtAlpha_Neck01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LookAtAlpha_Spine03;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LookAtAlpha_Spine02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LookAtAlpha_Spine01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PlayerCapsuleHalfHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bUseIsEyeTrackingOnly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float EyeTrackingOnlyInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ACharacter* Character;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float EyeUpDown;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float EyeLeftRight;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LookAtAlpha_Head_Normalized;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LookAtAlpha_Neck02_Normalized;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LookAtAlpha_Neck01_Normalized;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LookAtAlpha_Spine03_Normalized;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LookAtAlpha_Spine02_Normalized;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LookAtAlpha_Spine01_Normalized;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator BodyLookAtRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator HeadLookAtRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator RightEyeLookAtRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator LeftEyeLookAtRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float EyeTrackingOnlyMultiplier;
    
public:
    UTWDAnimInstanceHeadLook();
};

