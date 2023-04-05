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
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
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
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float GripPinkyClench;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float GripRingClenchRaw;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float GripRingClench;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float GripMiddleClenchRaw;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float GripMiddleClench;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float GripPose;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float PointingClenchRaw;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float PointingClench;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float PointingPose;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ThumbClenchRaw;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ThumbClench;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ThumbPose;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    EControllerHand hand;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FSDIHandPoseInfo HandPoseInfo;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bHandPoseInfoForHighlight;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FName CachedSnapshot;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float CachedAlpha;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float OverridePoseInterpSpeed;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bCustomLinkedHandPoseAnimInstance;
    
    UPROPERTY(BlueprintReadOnly, Transient)
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

