#include "SDICoreCableComponent.h"

class UPrimitiveComponent;

void USDICoreCableComponent::UnBindStart() {
}

void USDICoreCableComponent::UnBindEnd() {
}

void USDICoreCableComponent::SetRenderSplineTension(float RenderSplineTension) {
}

void USDICoreCableComponent::SetRenderMaterialLength(float RenderMaterialLength) {
}

void USDICoreCableComponent::SetRenderInvertMaterial(bool bInvert) {
}

void USDICoreCableComponent::SetPhysical(bool bPhysical) {
}

void USDICoreCableComponent::SetMinimumLOD(int32 NewMinimumLOD) {
}

void USDICoreCableComponent::SetForcedLOD(int32 NewForcedLOD) {
}

void USDICoreCableComponent::SetCableRadius(float Radius) {
}

void USDICoreCableComponent::SetBodySegmentRadiusOverride(float Radius) {
}

void USDICoreCableComponent::OnWake(UPrimitiveComponent* WakingComponent, FName BoneName) {
}

bool USDICoreCableComponent::IsStartBound() const {
    return false;
}

bool USDICoreCableComponent::IsPhysical() const {
    return false;
}

bool USDICoreCableComponent::IsEndBound() const {
    return false;
}

void USDICoreCableComponent::InitFromWorldSpline(const FInterpCurveVector& InSpline) {
}

void USDICoreCableComponent::InitFromWorldParticles(const TArray<FSDISimulatedCableParticle>& InParticles, float Tension) {
}

void USDICoreCableComponent::InitFromWorldControlPoints(const TArray<FVector>& Points, float Tension) {
}

void USDICoreCableComponent::InitFromWaveform(FTransform WorldTransform, float Length, const FSDIWaveformAxis& SinAxis, const FSDIWaveformAxis& CosAxis, float SinOffsetDeg, float CosOffsetDeg, int32 ResolutionPerMeter, float Tension) {
}

void USDICoreCableComponent::InitFromSineWave(FTransform WorldTransform, float Length, const FSDIWaveformAxis& SinAxis, float SinOffsetDeg, int32 ResolutionPerMeter, float Tension) {
}

void USDICoreCableComponent::InitFromRelativeSpline(FTransform WorldTransform, const FInterpCurveVector& InSpline) {
}

void USDICoreCableComponent::InitFromRelativeParticles(FTransform WorldTransform, const TArray<FSDISimulatedCableParticle>& InParticles, float Tension) {
}

void USDICoreCableComponent::InitFromRelativeControlPoints(FTransform WorldTransform, const TArray<FVector>& Points, float Tension) {
}

float USDICoreCableComponent::GetSegmentBodyRadius() const {
    return 0.0f;
}

TArray<FSDISimulatedCableParticle> USDICoreCableComponent::GetRelativeParticles() const {
    return TArray<FSDISimulatedCableParticle>();
}

int32 USDICoreCableComponent::GetNumLODs() const {
    return 0;
}

float USDICoreCableComponent::GetCurrentTautThreshold(float TautLength) const {
    return 0.0f;
}

void USDICoreCableComponent::DrawDebugBodies(FLinearColor Color, bool bPersistent, float LifeTime) {
}

bool USDICoreCableComponent::BindStartAtLocation(FVector Location) {
    return false;
}

bool USDICoreCableComponent::BindStart(UPrimitiveComponent* PrimComp, FVector RelativePos, FName PrimBodyName) {
    return false;
}

bool USDICoreCableComponent::BindEndAtLocation(FVector Location) {
    return false;
}

bool USDICoreCableComponent::BindEnd(UPrimitiveComponent* PrimComp, FVector RelativePos, FName PrimBodyName) {
    return false;
}

USDICoreCableComponent::USDICoreCableComponent() {
    this->CableRadius = 1.50f;
    this->CableLength = 100.00f;
    this->InitSplineComponentResolution = 100;
    this->bIsPhysical = false;
    this->bAllowStartPhysicsTick = false;
    this->BodySegmentRadiusOverride = 0.00f;
    this->BodySegmentLength = 20.00f;
    this->SwingLimitDegrees = 60.00f;
    this->bAdjustMassToMatchVisuals = true;
    this->bDistributeMassEqually = true;
    this->bFixedStart = false;
    this->bFixedEnd = false;
    this->TautThresholdCurve = NULL;
    this->TautThreshold = 1.00f;
    this->MaintainTautThresholdCurve = NULL;
    this->MaintainTautThresholdPct = 0.05f;
    this->bEnforceTautPhysics = true;
    this->bEnforceTautPhysicsSuspendSimulation = false;
    this->TautPhysicsBlendTime = 0.50f;
    this->TautElasticityScale = 0.00f;
    this->MinTautElasticity = 0.00f;
    this->MaxTautElasticity = 512.00f;
    this->TautElasticityRecoverySpeed = 100.00f;
    this->bUseTautHelperConstraints = false;
    this->bSoftTautHelperConstraints = true;
    this->SoftTautHelperConstraintStiffness = 50.00f;
    this->SoftTautHelperConstraintDamping = 5.00f;
    this->BaseGravityMultiplier = 1.00f;
    this->bUseCustomGravity = true;
    this->bCustomGravityDisableOnTaut = false;
    this->MinCustomGravityPct = 0.25f;
    this->CustomGravityTautPctStart = 0.90f;
    this->bAllowSegmentSubdivision = true;
    this->MinBodySegmentLength = 20.00f;
    this->MaxBodySegmentLength = 100.00f;
    this->SubdivisionDelay = 0.00f;
    this->SegmentSplitDistance = 256.00f;
    this->SegmentMergeDistance = 512.00f;
    this->SegmentMergeMaxAngleDeg = 10.00f;
    this->bDebugRenderCustomGravity = false;
    this->bDebugRenderPrePhysicsBodies = false;
    this->bDebugRenderPostPhysicsBodies = false;
    this->bDebugRenderTautConstraints = false;
    this->bDebugRenderVisualControlPoints = false;
    this->Material = NULL;
    this->MaterialLength = 100.00f;
    this->bInvertMaterial = false;
    this->SplineTension = 0.00f;
    this->RenderUpdateMovementThreshold = 0.25f;
    this->LODSettings.AddDefaulted(5);
    this->BasePhysicsBodySetup = NULL;
    this->bBodyInstanceSettingsValid = false;
    this->SegmentMergeMinDotP = 0.00f;
    this->bAreAnyBodiesAwake = false;
    this->bWereAnyBodiesAwake = false;
    this->bSpecialCaseDoubleBoundTautDisabled = false;
    this->SubdivisionTimer = 0.00f;
    this->bInitialPhysicsCreated = false;
}

