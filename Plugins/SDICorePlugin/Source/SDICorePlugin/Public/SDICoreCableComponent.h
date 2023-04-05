#pragma once
#include "CoreMinimal.h"
#include "PerPlatformProperties.h"
#include "SDIMultiBodyPrimitiveComponent.h"
#include "Engine/EngineTypes.h"
#include "SDIBlendOption.h"
#include "SDICableBind.h"
#include "SDICableLODSettings.h"
#include "SDIAuxTickFunction.h"
#include "SDIWaveformAxis.h"
#include "SDISimulatedCableParticle.h"
#include "SDIAttachmentInfo.h"
#include "PhysicsEngine/BodyInstance.h"
#include "UObject/NoExportTypes.h"
#include "SDIBooleanState.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDICoreCableComponent.generated.h"

class UMaterialInterface;
class UBodySetup;
class UCurveFloat;
class UPrimitiveComponent;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDICOREPLUGIN_API USDICoreCableComponent : public USDIMultiBodyPrimitiveComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float CableRadius;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float CableLength;
    
    UPROPERTY(EditAnywhere)
    FComponentReference InitSplineComponent;
    
    UPROPERTY(EditAnywhere)
    int32 InitSplineComponentResolution;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bIsPhysical;
    
    UPROPERTY(EditAnywhere)
    bool bAllowStartPhysicsTick;
    
    UPROPERTY(EditAnywhere)
    TArray<FSDICableBind> BindPoints;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float BodySegmentRadiusOverride;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float BodySegmentLength;
    
    UPROPERTY(EditAnywhere)
    float SwingLimitDegrees;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bAdjustMassToMatchVisuals;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bDistributeMassEqually;
    
    UPROPERTY(EditAnywhere)
    bool bFixedStart;
    
    UPROPERTY(EditAnywhere)
    bool bFixedEnd;
    
    UPROPERTY(EditAnywhere)
    UCurveFloat* TautThresholdCurve;
    
    UPROPERTY(EditAnywhere)
    float TautThreshold;
    
    UPROPERTY(EditAnywhere)
    UCurveFloat* MaintainTautThresholdCurve;
    
    UPROPERTY(EditAnywhere)
    float MaintainTautThresholdPct;
    
    UPROPERTY(EditAnywhere)
    bool bEnforceTautPhysics;
    
    UPROPERTY(EditAnywhere)
    bool bEnforceTautPhysicsSuspendSimulation;
    
    UPROPERTY(EditAnywhere)
    float TautPhysicsBlendTime;
    
    UPROPERTY(EditAnywhere)
    FSDIBlendOption TautPhysicsBlend;
    
    UPROPERTY(EditAnywhere)
    float TautElasticityScale;
    
    UPROPERTY(EditAnywhere)
    float MinTautElasticity;
    
    UPROPERTY(EditAnywhere)
    float MaxTautElasticity;
    
    UPROPERTY(EditAnywhere)
    float TautElasticityRecoverySpeed;
    
    UPROPERTY(EditAnywhere)
    bool bUseTautHelperConstraints;
    
    UPROPERTY(EditAnywhere)
    bool bSoftTautHelperConstraints;
    
    UPROPERTY(EditAnywhere)
    float SoftTautHelperConstraintStiffness;
    
    UPROPERTY(EditAnywhere)
    float SoftTautHelperConstraintDamping;
    
    UPROPERTY(EditAnywhere)
    float BaseGravityMultiplier;
    
    UPROPERTY(EditAnywhere)
    bool bUseCustomGravity;
    
    UPROPERTY(EditAnywhere)
    bool bCustomGravityDisableOnTaut;
    
    UPROPERTY(EditAnywhere)
    float MinCustomGravityPct;
    
    UPROPERTY(EditAnywhere)
    FSDIBlendOption CustomGravityLengthBlend;
    
    UPROPERTY(EditAnywhere)
    float CustomGravityTautPctStart;
    
    UPROPERTY(EditAnywhere)
    FSDIBlendOption CustomGravityTautPctBlend;
    
    UPROPERTY(EditAnywhere)
    bool bAllowSegmentSubdivision;
    
    UPROPERTY(EditAnywhere)
    float MinBodySegmentLength;
    
    UPROPERTY(EditAnywhere)
    float MaxBodySegmentLength;
    
    UPROPERTY(EditAnywhere)
    float SubdivisionDelay;
    
    UPROPERTY(EditAnywhere)
    float SegmentSplitDistance;
    
    UPROPERTY(EditAnywhere)
    float SegmentMergeDistance;
    
    UPROPERTY(EditAnywhere)
    float SegmentMergeMaxAngleDeg;
    
    UPROPERTY(EditAnywhere)
    bool bDebugRenderCustomGravity;
    
    UPROPERTY(EditAnywhere)
    bool bDebugRenderPrePhysicsBodies;
    
    UPROPERTY(EditAnywhere)
    bool bDebugRenderPostPhysicsBodies;
    
    UPROPERTY(EditAnywhere)
    bool bDebugRenderTautConstraints;
    
    UPROPERTY(EditAnywhere)
    bool bDebugRenderVisualControlPoints;
    
    UPROPERTY(EditAnywhere)
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float MaterialLength;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bInvertMaterial;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float SplineTension;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float RenderUpdateMovementThreshold;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<FSDICableLODSettings> LODSettings;
    
    UPROPERTY(EditAnywhere)
    FPerPlatformInt MinimumLOD;
    
    UPROPERTY(EditAnywhere)
    FPerPlatformInt ForcedLOD;
    
    UPROPERTY()
    FSDIAuxTickFunction StartPhysicsTickFunction;
    
    UPROPERTY()
    FSDIAuxTickFunction EndPhysicsTickFunction;
    
    UPROPERTY(Transient)
    TArray<UBodySetup*> PhysicsBodySetups;
    
    UPROPERTY(Transient)
    UBodySetup* BasePhysicsBodySetup;
    
    UPROPERTY(Transient)
    TArray<FSDISimulatedCableParticle> Particles;
    
    UPROPERTY(Transient)
    TMap<FName, int32> TautConstraintBodyRefs;
    
    UPROPERTY(Transient)
    TMap<FName, FSDIAttachmentInfo> BoundConstraintBodies;
    
    UPROPERTY(Transient)
    bool bBodyInstanceSettingsValid;
    
    UPROPERTY(Transient)
    FBodyInstance BodyInstanceSettings;
    
    UPROPERTY(Transient)
    float SegmentMergeMinDotP;
    
    UPROPERTY(Transient)
    FInterpCurveVector PhysicsSplineSource;
    
    UPROPERTY(Transient)
    bool bAreAnyBodiesAwake;
    
    UPROPERTY(Transient)
    bool bWereAnyBodiesAwake;
    
    UPROPERTY(Transient)
    bool bSpecialCaseDoubleBoundTautDisabled;
    
    UPROPERTY(Transient)
    float SubdivisionTimer;
    
    UPROPERTY(Transient)
    bool bInitialPhysicsCreated;
    
    UPROPERTY(Transient)
    FSDIBooleanState SimulatePhysicsOnBeginPlay;
    
public:
    USDICoreCableComponent();
    UFUNCTION(BlueprintCallable)
    void UnBindStart();
    
    UFUNCTION(BlueprintCallable)
    void UnBindEnd();
    
    UFUNCTION(BlueprintCallable)
    void SetRenderSplineTension(float RenderSplineTension);
    
    UFUNCTION(BlueprintCallable)
    void SetRenderMaterialLength(float RenderMaterialLength);
    
    UFUNCTION(BlueprintCallable)
    void SetRenderInvertMaterial(bool bInvert);
    
    UFUNCTION(BlueprintCallable)
    void SetPhysical(bool bPhysical);
    
    UFUNCTION(BlueprintCallable)
    void SetMinimumLOD(int32 NewMinimumLOD);
    
    UFUNCTION(BlueprintCallable)
    void SetForcedLOD(int32 NewForcedLOD);
    
    UFUNCTION(BlueprintCallable)
    void SetCableRadius(float Radius);
    
    UFUNCTION(BlueprintCallable)
    void SetBodySegmentRadiusOverride(float Radius);
    
protected:
    UFUNCTION()
    void OnWake(UPrimitiveComponent* WakingComponent, FName BoneName);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsStartBound() const;
    
    UFUNCTION(BlueprintPure)
    bool IsPhysical() const;
    
    UFUNCTION(BlueprintPure)
    bool IsEndBound() const;
    
    UFUNCTION(BlueprintCallable)
    void InitFromWorldSpline(const FInterpCurveVector& InSpline);
    
    UFUNCTION(BlueprintCallable)
    void InitFromWorldParticles(const TArray<FSDISimulatedCableParticle>& InParticles, float Tension);
    
    UFUNCTION(BlueprintCallable)
    void InitFromWorldControlPoints(const TArray<FVector>& Points, float Tension);
    
    UFUNCTION(BlueprintCallable)
    void InitFromWaveform(FTransform WorldTransform, float Length, const FSDIWaveformAxis& SinAxis, const FSDIWaveformAxis& CosAxis, float SinOffsetDeg, float CosOffsetDeg, int32 ResolutionPerMeter, float Tension);
    
    UFUNCTION(BlueprintCallable)
    void InitFromSineWave(FTransform WorldTransform, float Length, const FSDIWaveformAxis& SinAxis, float SinOffsetDeg, int32 ResolutionPerMeter, float Tension);
    
    UFUNCTION(BlueprintCallable)
    void InitFromRelativeSpline(FTransform WorldTransform, const FInterpCurveVector& InSpline);
    
    UFUNCTION(BlueprintCallable)
    void InitFromRelativeParticles(FTransform WorldTransform, const TArray<FSDISimulatedCableParticle>& InParticles, float Tension);
    
    UFUNCTION(BlueprintCallable)
    void InitFromRelativeControlPoints(FTransform WorldTransform, const TArray<FVector>& Points, float Tension);
    
    UFUNCTION(BlueprintPure)
    float GetSegmentBodyRadius() const;
    
    UFUNCTION(BlueprintPure)
    TArray<FSDISimulatedCableParticle> GetRelativeParticles() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetNumLODs() const;
    
    UFUNCTION(BlueprintPure)
    float GetCurrentTautThreshold(float TautLength) const;
    
    UFUNCTION(BlueprintCallable)
    void DrawDebugBodies(FLinearColor Color, bool bPersistent, float LifeTime);
    
    UFUNCTION(BlueprintCallable)
    bool BindStartAtLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    bool BindStart(UPrimitiveComponent* PrimComp, FVector RelativePos, FName PrimBodyName);
    
    UFUNCTION(BlueprintCallable)
    bool BindEndAtLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    bool BindEnd(UPrimitiveComponent* PrimComp, FVector RelativePos, FName PrimBodyName);
    
};

