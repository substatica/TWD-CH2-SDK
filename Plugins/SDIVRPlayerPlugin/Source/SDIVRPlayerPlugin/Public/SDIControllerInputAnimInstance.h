#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIAnimInstance.h"
#include "SDIHandPoseInfo.h"
#include "InputCoreTypes.h"
#include "SDIControllerInputAnimInstance.generated.h"

class USDIHandPoseAnimInstance;

UCLASS(NonTransient)
class SDIVRPLAYERPLUGIN_API USDIControllerInputAnimInstance : public USDIAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    float InterpSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float PoseInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName HandPoseLinkedGraphTag;
    
    UPROPERTY(Transient)
    float LockedClench;
    
    UPROPERTY(Transient)
    float Trigger;
    
    UPROPERTY(Transient)
    float GripPinky;
    
    UPROPERTY(Transient)
    float GripRing;
    
    UPROPERTY(Transient)
    float GripMiddle;
    
    UPROPERTY(Transient)
    float Pointing;
    
    UPROPERTY(Transient)
    float ThumbUp;
    
    UPROPERTY(Transient)
    float GripPinkyClenchRaw;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GripPinkyClench;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GripRingClenchRaw;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GripRingClench;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GripMiddleClenchRaw;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GripMiddleClench;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float GripPose;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PointingClenchRaw;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PointingClench;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PointingPose;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ThumbClenchRaw;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ThumbClench;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ThumbPose;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    EControllerHand hand;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIHandPoseInfo HandPoseInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bHandPoseInfoForHighlight;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FName CachedSnapshot;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CachedAlpha;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float OverridePoseInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bCustomLinkedHandPoseAnimInstance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TSubclassOf<USDIHandPoseAnimInstance> DefaultHandPoseAnimInstance;
    
public:
    USDIControllerInputAnimInstance();
    UFUNCTION(BlueprintCallable)
    void UnlockClench();
    
    UFUNCTION(BlueprintCallable)
    void SetHandPoseInfo(const FSDIHandPoseInfo& NewPose, bool bBlend, float BlendSpeed, bool bForHighlight);
    
    UFUNCTION(BlueprintCallable)
    void SetClench(float NewClench);
    
    UFUNCTION(BlueprintCallable)
    void LockClench(float NewClench);
    
    UFUNCTION(BlueprintPure)
    bool IsClenchLocked(float& OutLockedClench) const;
    
    UFUNCTION()
    void InputTrigger(float Value);
    
    UFUNCTION()
    void InputThumbUp(float Value);
    
    UFUNCTION()
    void InputPointing(float Value);
    
    UFUNCTION()
    void InputGripRing(float Value);
    
    UFUNCTION()
    void InputGripPinky(float Value);
    
    UFUNCTION()
    void InputGripMiddle(float Value);
    
    UFUNCTION()
    void InputGrip(float Value);
    
    UFUNCTION(BlueprintPure)
    float GetTrigger() const;
    
    UFUNCTION(BlueprintPure)
    float GetThumbUp() const;
    
    UFUNCTION(BlueprintPure)
    float GetPointing() const;
    
    UFUNCTION(BlueprintPure)
    float GetGripRing() const;
    
    UFUNCTION(BlueprintPure)
    float GetGripPinky() const;
    
    UFUNCTION(BlueprintPure)
    float GetGripMiddle() const;
    
    UFUNCTION(BlueprintPure)
    float GetGrip() const;
    
};

