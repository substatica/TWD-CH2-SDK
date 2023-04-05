#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/NoExportTypes.h"
#include "SDISimulatedCableParticle.h"
#include "SDIWaveformAxis.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SDICoreCableUtil.generated.h"

class UObject;
class AActor;

UCLASS(BlueprintType)
class SDICOREPLUGIN_API USDICoreCableUtil : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USDICoreCableUtil();
    UFUNCTION(BlueprintCallable)
    static float SetSimulatedCableParticlesFromWaveForm(UPARAM(Ref) TArray<FSDISimulatedCableParticle>& OutParticles, FTransform Transform, float Length, const FSDIWaveformAxis& SinAxis, const FSDIWaveformAxis& CosAxis, float SinOffsetDeg, float CosOffsetDeg, int32 ResolutionPerMeter, bool bRelative);
    
    UFUNCTION(BlueprintCallable)
    static float SetSimulatedCableParticlesFromSineWave(UPARAM(Ref) TArray<FSDISimulatedCableParticle>& OutParticles, FTransform Transform, float Length, const FSDIWaveformAxis& SinAxis, float SinOffsetDeg, int32 ResolutionPerMeter, bool bRelative);
    
    UFUNCTION(BlueprintCallable)
    static float SetSimulatedCableParticlesFromInterpCurveVector(UPARAM(Ref) TArray<FSDISimulatedCableParticle>& Particles, const FInterpCurveVector& Spline, int32 Resolution, bool bStartFixed, bool bEndFixed);
    
    UFUNCTION(BlueprintCallable)
    static float SetSimulatedCableParticlesFromControlPoints(UPARAM(Ref) TArray<FSDISimulatedCableParticle>& Particles, const TArray<FVector>& Points, bool bStartFixed, bool bEndFixed);
    
    UFUNCTION(BlueprintCallable)
    static void SetInterpCurveVectorFromWaveform(UPARAM(Ref) FInterpCurveVector& OutSpline, FTransform Transform, float Length, const FSDIWaveformAxis& SinAxis, const FSDIWaveformAxis& CosAxis, float SinOffsetDeg, float CosOffsetDeg, int32 ResolutionPerMeter, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints, bool bRelative);
    
    UFUNCTION(BlueprintCallable)
    static void SetInterpCurveVectorFromSineWave(UPARAM(Ref) FInterpCurveVector& OutSpline, FTransform Transform, float Length, const FSDIWaveformAxis& SinAxis, float SinOffsetDeg, int32 ResolutionPerMeter, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints, bool bRelative);
    
    UFUNCTION(BlueprintCallable)
    static void SetInterpCurveVectorFromSimulatedCableParticlesWithTransform(UPARAM(Ref) FInterpCurveVector& OutSpline, const FTransform& Transform, const TArray<FSDISimulatedCableParticle>& Particles, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints);
    
    UFUNCTION(BlueprintCallable)
    static void SetInterpCurveVectorFromSimulatedCableParticles(UPARAM(Ref) FInterpCurveVector& OutSpline, const TArray<FSDISimulatedCableParticle>& Particles, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints);
    
    UFUNCTION(BlueprintCallable)
    static void SetControlPointsFromSimulatedCableParticles(UPARAM(Ref) TArray<FVector>& OutPoints, const TArray<FSDISimulatedCableParticle>& Particles);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void K2TickSimulatedCableParticles(const UObject* WorldContextObject, UPARAM(Ref) TArray<FSDISimulatedCableParticle>& Particles, FTransform LocalToWorld, float Radius, float DeltaTime, FVector Gravity, bool bCollide, const TArray<AActor*>& ActorsToIgnore, TEnumAsByte<ECollisionChannel> TraceChannel, bool bUseCapsuleCollisions, float SubstepTime, int32 SolverIterations);
    
};

