#include "SDICoreCableUtil.h"

class UObject;
class AActor;

float USDICoreCableUtil::SetSimulatedCableParticlesFromWaveForm(TArray<FSDISimulatedCableParticle>& OutParticles, FTransform Transform, float Length, const FSDIWaveformAxis& SinAxis, const FSDIWaveformAxis& CosAxis, float SinOffsetDeg, float CosOffsetDeg, int32 ResolutionPerMeter, bool bRelative) {
    return 0.0f;
}

float USDICoreCableUtil::SetSimulatedCableParticlesFromSineWave(TArray<FSDISimulatedCableParticle>& OutParticles, FTransform Transform, float Length, const FSDIWaveformAxis& SinAxis, float SinOffsetDeg, int32 ResolutionPerMeter, bool bRelative) {
    return 0.0f;
}

float USDICoreCableUtil::SetSimulatedCableParticlesFromInterpCurveVector(TArray<FSDISimulatedCableParticle>& Particles, const FInterpCurveVector& Spline, int32 Resolution, bool bStartFixed, bool bEndFixed) {
    return 0.0f;
}

float USDICoreCableUtil::SetSimulatedCableParticlesFromControlPoints(TArray<FSDISimulatedCableParticle>& Particles, const TArray<FVector>& Points, bool bStartFixed, bool bEndFixed) {
    return 0.0f;
}

void USDICoreCableUtil::SetInterpCurveVectorFromWaveform(FInterpCurveVector& OutSpline, FTransform Transform, float Length, const FSDIWaveformAxis& SinAxis, const FSDIWaveformAxis& CosAxis, float SinOffsetDeg, float CosOffsetDeg, int32 ResolutionPerMeter, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints, bool bRelative) {
}

void USDICoreCableUtil::SetInterpCurveVectorFromSineWave(FInterpCurveVector& OutSpline, FTransform Transform, float Length, const FSDIWaveformAxis& SinAxis, float SinOffsetDeg, int32 ResolutionPerMeter, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints, bool bRelative) {
}

void USDICoreCableUtil::SetInterpCurveVectorFromSimulatedCableParticlesWithTransform(FInterpCurveVector& OutSpline, const FTransform& Transform, const TArray<FSDISimulatedCableParticle>& Particles, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints) {
}

void USDICoreCableUtil::SetInterpCurveVectorFromSimulatedCableParticles(FInterpCurveVector& OutSpline, const TArray<FSDISimulatedCableParticle>& Particles, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints) {
}

void USDICoreCableUtil::SetControlPointsFromSimulatedCableParticles(TArray<FVector>& OutPoints, const TArray<FSDISimulatedCableParticle>& Particles) {
}

void USDICoreCableUtil::K2TickSimulatedCableParticles(const UObject* WorldContextObject, TArray<FSDISimulatedCableParticle>& Particles, FTransform LocalToWorld, float Radius, float DeltaTime, FVector Gravity, bool bCollide, const TArray<AActor*>& ActorsToIgnore, TEnumAsByte<ECollisionChannel> TraceChannel, bool bUseCapsuleCollisions, float SubstepTime, int32 SolverIterations) {
}

USDICoreCableUtil::USDICoreCableUtil() {
}

