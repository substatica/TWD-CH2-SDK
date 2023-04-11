#include "SDIPlayerController.h"
#include "Templates/SubclassOf.h"

class UObject;
class UObject;
class UCurveFloat;
class ASDIInventoryActor;
class AActor;
class ASDIPlayerHand;
class ASDINonVRObjectInteractionActor;
class ASDIInteractiveHighlightManager;

void ASDIPlayerController::ToggleMusic() {
}

void ASDIPlayerController::ToggleMotionControllerTrackingAdjustment() {
}

void ASDIPlayerController::ToggleDebugRenderMotionControllerTracking() {
}

void ASDIPlayerController::SynchronizeHapticEffectId(int32 ID) {
}

void ASDIPlayerController::SynchronizeHapticEffect(UObject* HapticEffect) {
}

void ASDIPlayerController::StopNonVRObjectInteraction() {
}

void ASDIPlayerController::StopHapticsByValue(EControllerHand hand, UObject* EffectOwner) {
}

void ASDIPlayerController::StopHapticEffectObject(UObject* HapticEffect, EControllerHand hand, UObject* EffectOwner) {
}

bool ASDIPlayerController::StopHapticEffectId(int32 ID) {
    return false;
}

void ASDIPlayerController::StopEditing() {
}

void ASDIPlayerController::StopAllHapticEffects(EControllerHand hand, UObject* EffectOwner) {
}

bool ASDIPlayerController::StaticStopHapticEffectId(const UObject* WorldContextObject, int32 ID) {
    return false;
}

bool ASDIPlayerController::ShouldUseSystemResetHMD() const {
    return false;
}

void ASDIPlayerController::SetVignetteSettings(float StrengthMultiplier, float OpacityMultiplier, float Comfort) {
}

void ASDIPlayerController::SetHapticsByValueSDI(const float Frequency, const float Amplitude, EControllerHand hand, UObject* EffectOwner) {
}

void ASDIPlayerController::SetHandControllerOffset(const FString& hand, const FString& Axis, float Value) {
}

void ASDIPlayerController::SetGripOffset(const FString& hand, const FString& Axis, float Value) {
}

void ASDIPlayerController::ServerGiveItemTo_Implementation(ASDIInventoryActor* Inventory, AActor* NewOwner) {
}
bool ASDIPlayerController::ServerGiveItemTo_Validate(ASDIInventoryActor* Inventory, AActor* NewOwner) {
    return true;
}

void ASDIPlayerController::ServerCheatServerCommand_Implementation(const FString& Cmd) {
}
bool ASDIPlayerController::ServerCheatServerCommand_Validate(const FString& Cmd) {
    return true;
}

void ASDIPlayerController::RopeTug_Implementation(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionTugParams& TugParams) {
}

void ASDIPlayerController::RopeStruggleTug_Implementation(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleTickParams& StruggleTickParams) {
}

float ASDIPlayerController::RopeStruggleTick_Implementation(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, float DeltaTime, const FSDIRopeReactionStruggleTickParams& StruggleTickParams) {
    return 0.0f;
}

void ASDIPlayerController::RopeStruggleStarted_Implementation(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleTickParams& StruggleTickParams) {
}

void ASDIPlayerController::RopeStruggleComplete_Implementation(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData, const FSDIRopeReactionStruggleCompleteParams& StruggleCompleteParams) {
}

void ASDIPlayerController::RopeStruggleCancelled_Implementation(UObject* InterfaceOwner, const FSDIRopeReactionData& RopeReactionData) {
}

void ASDIPlayerController::ResetVRToPlayer() {
}

void ASDIPlayerController::ResetVRToHMD() {
}

void ASDIPlayerController::ResetHandControllerOffset(const FString& hand) {
}

void ASDIPlayerController::ResetGripOffset(const FString& hand) {
}

void ASDIPlayerController::QuickTurnTowardsPoint(const FVector& Point, EAlphaBlendOption Blend, float OverrideTime, float ClampToIncrement, bool bDoFade, UCurveFloat* CustomCurve) {
}

void ASDIPlayerController::QuickTurnTowards(FVector Dir, EAlphaBlendOption Blend, float OverrideTime, float ClampToIncrement, bool bDoFade, UCurveFloat* CustomCurve) {
}

void ASDIPlayerController::QuickTurnTo(float AngleDeg, EAlphaBlendOption Blend, float OverrideTime, float ClampToIncrement, bool bDoFade, UCurveFloat* CustomCurve) {
}

void ASDIPlayerController::QuickTurn(float DegIncrement, EAlphaBlendOption Blend, float OverrideTime, float ClampToIncrement, bool bDoFade, UCurveFloat* CustomCurve) {
}

int32 ASDIPlayerController::PlayHapticEffectSDI(UObject* HapticEffect, EControllerHand hand, float Scale, float FrequencyScale, float PlaybackSpeed, bool bLoop, int32 Priority, UObject* EffectOwner) {
    return 0;
}

bool ASDIPlayerController::IsQuickTurning() const {
    return false;
}

bool ASDIPlayerController::IsPointInView(const FVector& Point, bool bHorizontalOnly) const {
    return false;
}

bool ASDIPlayerController::IsPlayingHapticsByValue(EControllerHand hand, UObject* EffectOwner) const {
    return false;
}

bool ASDIPlayerController::IsPlayingHapticEffectId(int32 ID) const {
    return false;
}

bool ASDIPlayerController::IsPlayingHapticEffect(UObject* HapticEffect, EControllerHand hand, UObject* EffectOwner) const {
    return false;
}

bool ASDIPlayerController::IsNonVRObjectInteracting() const {
    return false;
}

bool ASDIPlayerController::IsEditingOffsets() const {
    return false;
}

bool ASDIPlayerController::IsDirectionInView(const FVector& Dir, bool bHorizontalOnly) const {
    return false;
}

bool ASDIPlayerController::IsCameraUnderWater() const {
    return false;
}

void ASDIPlayerController::InputSystemResetHMD() {
}

void ASDIPlayerController::InputResetHMD() {
}

void ASDIPlayerController::InputQuickTurnRight(float Value) {
}

void ASDIPlayerController::InputQuickTurnLeft(float Value) {
}

void ASDIPlayerController::InputQuickTurnAxis(float Value) {
}

void ASDIPlayerController::InputQuickTurn180(float Value) {
}

void ASDIPlayerController::InputIncEditOffsetZ() {
}

void ASDIPlayerController::InputIncEditOffsetYaw() {
}

void ASDIPlayerController::InputIncEditOffsetY() {
}

void ASDIPlayerController::InputIncEditOffsetX() {
}

void ASDIPlayerController::InputIncEditOffsetRoll() {
}

void ASDIPlayerController::InputIncEditOffsetPitch() {
}

void ASDIPlayerController::InputEditOffsetRotationReleased() {
}

void ASDIPlayerController::InputEditOffsetRotationPressed() {
}

void ASDIPlayerController::InputEditOffsetLocationReleased() {
}

void ASDIPlayerController::InputEditOffsetLocationPressed() {
}

void ASDIPlayerController::InputDecEditOffsetZ() {
}

void ASDIPlayerController::InputDecEditOffsetYaw() {
}

void ASDIPlayerController::InputDecEditOffsetY() {
}

void ASDIPlayerController::InputDecEditOffsetX() {
}

void ASDIPlayerController::InputDecEditOffsetRoll() {
}

void ASDIPlayerController::InputDecEditOffsetPitch() {
}

void ASDIPlayerController::InputAxisRightTriggerHaptic(float Value) {
}

void ASDIPlayerController::InputAxisLeftTriggerHaptic(float Value) {
}

void ASDIPlayerController::InputAxisEditOffsetZ(float Value) {
}

void ASDIPlayerController::InputAxisEditOffsetYaw(float Value) {
}

void ASDIPlayerController::InputAxisEditOffsetY(float Value) {
}

void ASDIPlayerController::InputAxisEditOffsetX(float Value) {
}

void ASDIPlayerController::InputAxisEditOffsetRoll(float Value) {
}

void ASDIPlayerController::InputAxisEditOffsetPitch(float Value) {
}

void ASDIPlayerController::GetVignetteSettings(float& StrengthMultiplier, float& OpacityMultiplier, float& Comfort) const {
}

TSubclassOf<ASDIPlayerHand> ASDIPlayerController::GetPlayerHandBlueprint(EControllerHand hand) const {
    return NULL;
}

ASDIPlayerHand* ASDIPlayerController::GetPlayerHand(EControllerHand hand) const {
    return NULL;
}

ASDIPlayerHand* ASDIPlayerController::GetOtherPlayerHand(EControllerHand hand) const {
    return NULL;
}

TSubclassOf<ASDINonVRObjectInteractionActor> ASDIPlayerController::GetNonVRObjectInteractionActorClass() const {
    return NULL;
}

ASDINonVRObjectInteractionActor* ASDIPlayerController::GetNonVRObjectInteractionActor() const {
    return NULL;
}

TSubclassOf<ASDIInteractiveHighlightManager> ASDIPlayerController::GetInteractiveHighlightManagerClass() const {
    return NULL;
}

ASDIInteractiveHighlightManager* ASDIPlayerController::GetHighlightManager() const {
    return NULL;
}

ASDIPlayerHand* ASDIPlayerController::GetHapticFeedbackPlayerHand(int32 ID) const {
    return NULL;
}

EControllerHand ASDIPlayerController::GetHapticFeedbackHand(int32 ID) const {
    return EControllerHand::Left;
}

UObject* ASDIPlayerController::GetHapticFeedbackEffect(int32 ID) const {
    return NULL;
}

FTransform ASDIPlayerController::GetCameraTransform2D() const {
    return FTransform{};
}

FTransform ASDIPlayerController::GetCameraTransform() const {
    return FTransform{};
}

FVector ASDIPlayerController::GetCameraRight2D() const {
    return FVector{};
}

FVector ASDIPlayerController::GetCameraForward2D() const {
    return FVector{};
}

void ASDIPlayerController::EditHandControllerOffset(const FString& hand, float LocIncrement, float RotIncrement) {
}

void ASDIPlayerController::EditGripOffset(const FString& hand, float LocIncrement, float RotIncrement) {
}

void ASDIPlayerController::DelayQuickTurnInput(float Delay) {
}

float ASDIPlayerController::ComputeQuickTurnTime(float DegIncrement) const {
    return 0.0f;
}

void ASDIPlayerController::ComputeQuickTurnTargetAngle(float& Start, float& Target, float DegIncrement, float ClampToIncrement) const {
}

bool ASDIPlayerController::AdjustHapticEffectScaleId(int32 ID, float Scale) {
    return false;
}

void ASDIPlayerController::AdjustHapticEffectScale(UObject* HapticEffect, float Scale, EControllerHand hand, UObject* EffectOwner) {
}

bool ASDIPlayerController::AdjustHapticEffectPlaybackSpeedId(int32 ID, float PlaybackSpeed) {
    return false;
}

void ASDIPlayerController::AdjustHapticEffectPlaybackSpeed(UObject* HapticEffect, float PlaybackSpeed, EControllerHand hand, UObject* EffectOwner) {
}

bool ASDIPlayerController::AdjustHapticEffectFrequencyScaleId(int32 ID, float FrequencyScale) {
    return false;
}

void ASDIPlayerController::AdjustHapticEffectFrequencyScale(UObject* HapticEffect, float FrequencyScale, EControllerHand hand, UObject* EffectOwner) {
}

void ASDIPlayerController::AddAbsYawInput(float Val) {
}

ASDIPlayerController::ASDIPlayerController() {
    this->DefaultInteractiveHighlightManagerClass = NULL;
    this->DefaultNonVRObjectInteractionActorClass = NULL;
    this->DefaultPlayerHandBlueprint = NULL;
    this->DefaultPlayerLeftHandBlueprint = NULL;
    this->OnScreenMaxHorizontalDegrees = 45.00f;
    this->OnScreenMaxVerticalDegrees = 45.00f;
    this->InteractLOSChannel = ECC_WorldDynamic;
    this->NonVRInteractCapsuleHalfHeightInner = 128.00f;
    this->NonVRInteractCapsuleRadiusInner = 32.00f;
    this->NonVRInteractCapsuleHalfHeightOuter = 512.00f;
    this->NonVRInteractCapsuleRadiusOuter = 64.00f;
    this->bFilterInteractionsToCylinder = false;
    this->bFilterInteractionsCylinderUseCameraXY = true;
    this->FilterInteractionsCylinderHeightAbove = 64.00f;
    this->FilterInteractionsCylinderHeightBelow = -64.00f;
    this->FilterInteractionsCylinderDistance = 128.00f;
    this->bNonVRFilterInteractionsToCylinder = true;
    this->bNonVRFilterInteractionsCylinderUseCameraXY = true;
    this->NonVRFilterInteractionsCylinderHeightAbove = 64.00f;
    this->NonVRFilterInteractionsCylinderHeightBelow = -64.00f;
    this->NonVRFilterInteractionsCylinderInnerDistance = 128.00f;
    this->NonVRFilterInteractionsCylinderOuterDistance = 384.00f;
    this->bUseSystemResetHMD = false;
    this->HighlightManager = NULL;
    this->NonVRObjectInteractionActor = NULL;
    this->PlayerHandLeft = NULL;
    this->PlayerHandRight = NULL;
    this->QuickTurnIncrement = 45.00f;
    this->bQuickTurnWorldIncrements = true;
    this->QuickTurnTime = 0.15f;
    this->QuickTurnBlend = EAlphaBlendOption::Linear;
    this->QuickTurnBlendCustomCurve = NULL;
    this->QuickTurnInputThreshold = 0.50f;
    this->QuickTurn180Time = 0.50f;
    this->QuickTurn180Blend = EAlphaBlendOption::Linear;
    this->QuickTurn180BlendCustomCurve = NULL;
    this->QuickTurn180MinPressTime = 0.25f;
    this->QuickTurn180InputThreshold = 0.70f;
    this->bQuickTurn180FadeScreen = true;
    this->QuickTurnRepeatTime = 0.50f;
    this->bQuickTurnRequireReleaseAfterIgnorance = false;
    this->QuickTurnTimer = -340282346638528859811704183484516925440.00f;
    this->QuickTurnDuration = 0.00f;
    this->QuickTurnStart = 0.00f;
    this->QuickTurnTarget = 0.00f;
    this->QuickTurnCurrentBlend = EAlphaBlendOption::Linear;
    this->QuickTurnCurrentBlendCustomCurve = NULL;
    this->bQuickTurn180Pressed = false;
    this->bQuickTurn180LockedOut = false;
    this->QuickTurn180PressedTime = 0.00f;
    this->bQuickTurnLeftPressed = false;
    this->bQuickTurnRightPressed = false;
    this->bQuickTurnWasIgnored = false;
    this->QuickTurnIgnoranceTimestamp = 0.00f;
    this->bEditingHandControllerOffset = false;
    this->bEditingGripOffset = false;
    this->EditOffsetLocIncrement = 0.00f;
    this->EditOffsetRotIncrement = 0.00f;
    this->EditHandEnum = EControllerHand::Left;
    this->bEditMirrorLeftHand = false;
    this->EditGripType = ESDIGripType::Any;
    this->bEditSingleHandedGrips = false;
    this->bEditTwoHandedGrips = false;
    this->OnScreenMinHorizontalCos = 0.00f;
    this->OnScreenMinVerticalCos = 0.00f;
    this->LeftTriggerHapticInput = 0.00f;
    this->RightTriggerHapticInput = 0.00f;
    this->SpawningHand = EControllerHand::AnyHand;
    this->bDisableMusic = false;
}

