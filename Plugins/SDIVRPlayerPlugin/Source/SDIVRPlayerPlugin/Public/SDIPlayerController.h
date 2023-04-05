#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDICorePlayerController.h"
#include "AlphaBlend.h"
#include "SDIHapticFeedbackManager.h"
#include "ESDIInteractRangeType.h"
#include "InputCoreTypes.h"
#include "Engine/EngineTypes.h"
#include "SDIRopeReactionTugParams.h"
#include "UObject/NoExportTypes.h"
#include "SDITimestampInputButton.h"
#include "UObject/NoExportTypes.h"
#include "ESDIGripType.h"
#include "SDIPlayerHandInteractComponentEntrySet.h"
#include "SDIInteractAsyncLOSResults.h"
#include "SDIWeaponFirearm_FiringWeaponDelegate.h"
#include "SDIRopeReactionData.h"
#include "SDIRopeReactionStruggleTickParams.h"
#include "SDIRopeReactionStruggleCompleteParams.h"
#include "UObject/NoExportTypes.h"
#include "SDIPlayerController.generated.h"

class ASDIInteractiveHighlightManager;
class ASDINonVRObjectInteractionActor;
class ASDIPlayerHand;
class UCurveFloat;
class ASDIInventoryActor;
class UHapticFeedbackEffect_Base;
class UObject;
class AActor;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIPlayerController : public ASDICorePlayerController {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ASDIInteractiveHighlightManager> DefaultInteractiveHighlightManagerClass;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TSubclassOf<ASDINonVRObjectInteractionActor> DefaultNonVRObjectInteractionActorClass;
    
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ASDIPlayerHand> DefaultPlayerHandBlueprint;
    
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ASDIPlayerHand> DefaultPlayerLeftHandBlueprint;
    
private:
    UPROPERTY(EditDefaultsOnly)
    FSDIHapticFeedbackManager LeftHandHapticFeedbackManager;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIHapticFeedbackManager RightHandHapticFeedbackManager;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIHapticFeedbackManager GunHapticFeedbackManager;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIHapticFeedbackManager HMDHapticFeedbackManager;
    
protected:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float OnScreenMaxHorizontalDegrees;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float OnScreenMaxVerticalDegrees;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TMap<ESDIInteractRangeType, TEnumAsByte<ECollisionChannel>> NonVROverlapChannels;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TEnumAsByte<ECollisionChannel> InteractLOSChannel;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRInteractCapsuleHalfHeightInner;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRInteractCapsuleRadiusInner;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRInteractCapsuleHalfHeightOuter;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRInteractCapsuleRadiusOuter;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bFilterInteractionsToCylinder;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bFilterInteractionsCylinderUseCameraXY;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float FilterInteractionsCylinderHeightAbove;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float FilterInteractionsCylinderHeightBelow;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float FilterInteractionsCylinderDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bNonVRFilterInteractionsToCylinder;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bNonVRFilterInteractionsCylinderUseCameraXY;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRFilterInteractionsCylinderHeightAbove;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRFilterInteractionsCylinderHeightBelow;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRFilterInteractionsCylinderInnerDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NonVRFilterInteractionsCylinderOuterDistance;
    
    UPROPERTY(Config, VisibleAnywhere)
    bool bUseSystemResetHMD;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    ASDIInteractiveHighlightManager* HighlightManager;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    ASDINonVRObjectInteractionActor* NonVRObjectInteractionActor;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    ASDIPlayerHand* PlayerHandLeft;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    ASDIPlayerHand* PlayerHandRight;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float QuickTurnIncrement;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bQuickTurnWorldIncrements;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float QuickTurnTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    EAlphaBlendOption QuickTurnBlend;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UCurveFloat* QuickTurnBlendCustomCurve;
    
    UPROPERTY(EditDefaultsOnly)
    float QuickTurnInputThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    float QuickTurn180Time;
    
    UPROPERTY(EditDefaultsOnly)
    EAlphaBlendOption QuickTurn180Blend;
    
    UPROPERTY(EditDefaultsOnly)
    UCurveFloat* QuickTurn180BlendCustomCurve;
    
    UPROPERTY(EditDefaultsOnly)
    float QuickTurn180MinPressTime;
    
    UPROPERTY(EditDefaultsOnly)
    float QuickTurn180InputThreshold;
    
    UPROPERTY(EditDefaultsOnly)
    bool bQuickTurn180FadeScreen;
    
    UPROPERTY(EditDefaultsOnly)
    float QuickTurnRepeatTime;
    
    UPROPERTY(EditDefaultsOnly)
    bool bQuickTurnRequireReleaseAfterIgnorance;
    
    UPROPERTY(Transient)
    float QuickTurnTimer;
    
    UPROPERTY(Transient)
    float QuickTurnDuration;
    
    UPROPERTY(Transient)
    float QuickTurnStart;
    
    UPROPERTY(Transient)
    float QuickTurnTarget;
    
    UPROPERTY(Transient)
    EAlphaBlendOption QuickTurnCurrentBlend;
    
    UPROPERTY(Transient)
    UCurveFloat* QuickTurnCurrentBlendCustomCurve;
    
    UPROPERTY(Transient)
    bool bQuickTurn180Pressed;
    
    UPROPERTY(Transient)
    bool bQuickTurn180LockedOut;
    
    UPROPERTY(Transient)
    float QuickTurn180PressedTime;
    
    UPROPERTY(Transient)
    bool bQuickTurnLeftPressed;
    
    UPROPERTY(Transient)
    bool bQuickTurnRightPressed;
    
    UPROPERTY(Transient)
    bool bQuickTurnWasIgnored;
    
    UPROPERTY(Transient)
    FRotator QuickTurnRotationInput;
    
    UPROPERTY(Transient)
    float QuickTurnIgnoranceTimestamp;
    
    UPROPERTY(Transient)
    bool bEditingHandControllerOffset;
    
    UPROPERTY(Transient)
    bool bEditingGripOffset;
    
    UPROPERTY(Transient)
    FSDITimestampInputButton InputEditOffsetLocationButton;
    
    UPROPERTY(Transient)
    FSDITimestampInputButton InputEditOffsetRotationButton;
    
    UPROPERTY(Transient)
    FTransform EditOffsetLocationWorldTransform;
    
    UPROPERTY(Transient)
    FTransform EditOffsetRotationWorldTransform;
    
    UPROPERTY(Transient)
    float EditOffsetLocIncrement;
    
    UPROPERTY(Transient)
    float EditOffsetRotIncrement;
    
    UPROPERTY(Transient)
    EControllerHand EditHandEnum;
    
    UPROPERTY(Transient)
    bool bEditMirrorLeftHand;
    
    UPROPERTY(Transient)
    ESDIGripType EditGripType;
    
    UPROPERTY(Transient)
    bool bEditSingleHandedGrips;
    
    UPROPERTY(Transient)
    bool bEditTwoHandedGrips;
    
    UPROPERTY(Transient)
    float OnScreenMinHorizontalCos;
    
    UPROPERTY(Transient)
    float OnScreenMinVerticalCos;
    
    UPROPERTY(Transient)
    TMap<EControllerHand, FSDIPlayerHandInteractComponentEntrySet> InteractEntryMap;
    
    UPROPERTY(Transient)
    TMap<EControllerHand, FSDIInteractAsyncLOSResults> InteractAsyncLOSResults;
    
    UPROPERTY(Transient)
    float LeftTriggerHapticInput;
    
    UPROPERTY(Transient)
    float RightTriggerHapticInput;
    
private:
    UPROPERTY(Transient)
    EControllerHand SpawningHand;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDIWeaponFirearm_FiringWeapon OnFiringWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bDisableMusic;
    
    ASDIPlayerController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(Exec)
    void ToggleMusic();
    
    UFUNCTION(Exec)
    void ToggleMotionControllerTrackingAdjustment();
    
    UFUNCTION(Exec)
    void ToggleDebugRenderMotionControllerTracking();
    
    UFUNCTION(BlueprintCallable)
    void SynchronizeHapticEffectId(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    void SynchronizeHapticEffect(UHapticFeedbackEffect_Base* HapticEffect);
    
    UFUNCTION(BlueprintCallable)
    void StopNonVRObjectInteraction();
    
    UFUNCTION(BlueprintCallable)
    void StopHapticsByValue(EControllerHand hand, UObject* EffectOwner);
    
    UFUNCTION(BlueprintCallable)
    void StopHapticEffectObject(UHapticFeedbackEffect_Base* HapticEffect, EControllerHand hand, UObject* EffectOwner);
    
    UFUNCTION(BlueprintCallable)
    bool StopHapticEffectId(int32 ID);
    
    UFUNCTION(Exec)
    void StopEditing();
    
    UFUNCTION(BlueprintCallable)
    void StopAllHapticEffects(EControllerHand hand, UObject* EffectOwner);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool StaticStopHapticEffectId(const UObject* WorldContextObject, int32 ID);
    
    UFUNCTION(BlueprintPure)
    bool ShouldUseSystemResetHMD() const;
    
    UFUNCTION(BlueprintCallable)
    void SetVignetteSettings(float StrengthMultiplier, float OpacityMultiplier, float Comfort);
    
    UFUNCTION(BlueprintCallable)
    void SetHapticsByValueSDI(const float Frequency, const float Amplitude, EControllerHand hand, UObject* EffectOwner);
    
    UFUNCTION(Exec)
    void SetHandControllerOffset(const FString& hand, const FString& Axis, float Value);
    
    UFUNCTION(Exec)
    void SetGripOffset(const FString& hand, const FString& Axis, float Value);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerGiveItemTo(ASDIInventoryActor* Inventory, AActor* NewOwner);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerCheatServerCommand(const FString& Cmd);
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void RopeTug(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionTugParams& TugParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void RopeStruggleTug(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleTickParams& StruggleTickParams);
    
    UFUNCTION(BlueprintNativeEvent)
    float RopeStruggleTick(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, float DeltaTime, const FSDIRopeReactionStruggleTickParams& StruggleTickParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void RopeStruggleStarted(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleTickParams& StruggleTickParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void RopeStruggleComplete(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleCompleteParams& StruggleCompleteParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void RopeStruggleCancelled(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData);
    
    UFUNCTION(BlueprintCallable)
    void ResetVRToPlayer();
    
    UFUNCTION(BlueprintCallable)
    void ResetVRToHMD();
    
    UFUNCTION(Exec)
    void ResetHandControllerOffset(const FString& hand);
    
    UFUNCTION(Exec)
    void ResetGripOffset(const FString& hand);
    
    UFUNCTION(BlueprintCallable)
    void QuickTurnTowardsPoint(const FVector& Point, EAlphaBlendOption Blend, float OverrideTime, float ClampToIncrement, bool bDoFade, UCurveFloat* CustomCurve);
    
    UFUNCTION(BlueprintCallable)
    void QuickTurnTowards(FVector Dir, EAlphaBlendOption Blend, float OverrideTime, float ClampToIncrement, bool bDoFade, UCurveFloat* CustomCurve);
    
    UFUNCTION(BlueprintCallable)
    void QuickTurnTo(float AngleDeg, EAlphaBlendOption Blend, float OverrideTime, float ClampToIncrement, bool bDoFade, UCurveFloat* CustomCurve);
    
    UFUNCTION(BlueprintCallable)
    void QuickTurn(float DegIncrement, EAlphaBlendOption Blend, float OverrideTime, float ClampToIncrement, bool bDoFade, UCurveFloat* CustomCurve);
    
    UFUNCTION(BlueprintCallable)
    int32 PlayHapticEffectSDI(UHapticFeedbackEffect_Base* HapticEffect, EControllerHand hand, float Scale, float FrequencyScale, float PlaybackSpeed, bool bLoop, int32 Priority, UObject* EffectOwner);
    
    UFUNCTION(BlueprintPure)
    bool IsQuickTurning() const;
    
    UFUNCTION(BlueprintPure)
    bool IsPointInView(const FVector& Point, bool bHorizontalOnly) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingHapticsByValue(EControllerHand hand, UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingHapticEffectId(int32 ID) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingHapticEffect(UHapticFeedbackEffect_Base* HapticEffect, EControllerHand hand, UObject* EffectOwner) const;
    
    UFUNCTION(BlueprintPure)
    bool IsNonVRObjectInteracting() const;
    
    UFUNCTION(BlueprintPure)
    bool IsEditingOffsets() const;
    
    UFUNCTION(BlueprintPure)
    bool IsDirectionInView(const FVector& Dir, bool bHorizontalOnly) const;
    
    UFUNCTION(BlueprintPure)
    bool IsCameraUnderWater() const;
    
    UFUNCTION()
    void InputSystemResetHMD();
    
    UFUNCTION()
    void InputResetHMD();
    
    UFUNCTION()
    void InputQuickTurnRight(float Value);
    
    UFUNCTION()
    void InputQuickTurnLeft(float Value);
    
    UFUNCTION()
    void InputQuickTurnAxis(float Value);
    
    UFUNCTION()
    void InputQuickTurn180(float Value);
    
    UFUNCTION()
    void InputIncEditOffsetZ();
    
    UFUNCTION()
    void InputIncEditOffsetYaw();
    
    UFUNCTION()
    void InputIncEditOffsetY();
    
    UFUNCTION()
    void InputIncEditOffsetX();
    
    UFUNCTION()
    void InputIncEditOffsetRoll();
    
    UFUNCTION()
    void InputIncEditOffsetPitch();
    
    UFUNCTION()
    void InputEditOffsetRotationReleased();
    
    UFUNCTION()
    void InputEditOffsetRotationPressed();
    
    UFUNCTION()
    void InputEditOffsetLocationReleased();
    
    UFUNCTION()
    void InputEditOffsetLocationPressed();
    
    UFUNCTION()
    void InputDecEditOffsetZ();
    
    UFUNCTION()
    void InputDecEditOffsetYaw();
    
    UFUNCTION()
    void InputDecEditOffsetY();
    
    UFUNCTION()
    void InputDecEditOffsetX();
    
    UFUNCTION()
    void InputDecEditOffsetRoll();
    
    UFUNCTION()
    void InputDecEditOffsetPitch();
    
    UFUNCTION()
    void InputAxisRightTriggerHaptic(float Value);
    
    UFUNCTION()
    void InputAxisLeftTriggerHaptic(float Value);
    
    UFUNCTION()
    void InputAxisEditOffsetZ(float Value);
    
    UFUNCTION()
    void InputAxisEditOffsetYaw(float Value);
    
    UFUNCTION()
    void InputAxisEditOffsetY(float Value);
    
    UFUNCTION()
    void InputAxisEditOffsetX(float Value);
    
    UFUNCTION()
    void InputAxisEditOffsetRoll(float Value);
    
    UFUNCTION()
    void InputAxisEditOffsetPitch(float Value);
    
    UFUNCTION(BlueprintPure)
    void GetVignetteSettings(float& StrengthMultiplier, float& OpacityMultiplier, float& Comfort) const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<ASDIPlayerHand> GetPlayerHandBlueprint(EControllerHand hand) const;
    
    UFUNCTION(BlueprintPure)
    ASDIPlayerHand* GetPlayerHand(EControllerHand hand) const;
    
    UFUNCTION(BlueprintPure)
    ASDIPlayerHand* GetOtherPlayerHand(EControllerHand hand) const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<ASDINonVRObjectInteractionActor> GetNonVRObjectInteractionActorClass() const;
    
    UFUNCTION(BlueprintPure)
    ASDINonVRObjectInteractionActor* GetNonVRObjectInteractionActor() const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<ASDIInteractiveHighlightManager> GetInteractiveHighlightManagerClass() const;
    
    UFUNCTION(BlueprintPure)
    ASDIInteractiveHighlightManager* GetHighlightManager() const;
    
    UFUNCTION(BlueprintPure)
    ASDIPlayerHand* GetHapticFeedbackPlayerHand(int32 ID) const;
    
    UFUNCTION(BlueprintPure)
    EControllerHand GetHapticFeedbackHand(int32 ID) const;
    
    UFUNCTION(BlueprintPure)
    UHapticFeedbackEffect_Base* GetHapticFeedbackEffect(int32 ID) const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetCameraTransform2D() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetCameraTransform() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetCameraRight2D() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetCameraForward2D() const;
    
    UFUNCTION(Exec)
    void EditHandControllerOffset(const FString& hand, float LocIncrement, float RotIncrement);
    
    UFUNCTION(Exec)
    void EditGripOffset(const FString& hand, float LocIncrement, float RotIncrement);
    
    UFUNCTION(BlueprintCallable)
    void DelayQuickTurnInput(float Delay);
    
    UFUNCTION(BlueprintPure)
    float ComputeQuickTurnTime(float DegIncrement) const;
    
    UFUNCTION(BlueprintPure)
    void ComputeQuickTurnTargetAngle(float& Start, float& Target, float DegIncrement, float ClampToIncrement) const;
    
    UFUNCTION(BlueprintCallable)
    bool AdjustHapticEffectScaleId(int32 ID, float Scale);
    
    UFUNCTION(BlueprintCallable)
    void AdjustHapticEffectScale(UHapticFeedbackEffect_Base* HapticEffect, float Scale, EControllerHand hand, UObject* EffectOwner);
    
    UFUNCTION(BlueprintCallable)
    bool AdjustHapticEffectPlaybackSpeedId(int32 ID, float PlaybackSpeed);
    
    UFUNCTION(BlueprintCallable)
    void AdjustHapticEffectPlaybackSpeed(UHapticFeedbackEffect_Base* HapticEffect, float PlaybackSpeed, EControllerHand hand, UObject* EffectOwner);
    
    UFUNCTION(BlueprintCallable)
    bool AdjustHapticEffectFrequencyScaleId(int32 ID, float FrequencyScale);
    
    UFUNCTION(BlueprintCallable)
    void AdjustHapticEffectFrequencyScale(UHapticFeedbackEffect_Base* HapticEffect, float FrequencyScale, EControllerHand hand, UObject* EffectOwner);
    
    UFUNCTION(BlueprintCallable)
    void AddAbsYawInput(float Val);
    
};

