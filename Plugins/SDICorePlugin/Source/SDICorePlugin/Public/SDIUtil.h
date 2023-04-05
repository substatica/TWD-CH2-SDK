#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UObject/NoExportTypes.h"
#include "Particles/WorldPSCPool.h"
#include "SDITargetSearchEntry.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AI/Navigation/NavigationTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SDITransformCollisionShape.h"
#include "SDIUtilRandomActorWeightListDynamicDelegateDelegate.h"
#include "SDICollisionShape.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Components/SplineComponent.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "Curves/CurveFloat.h"
#include "Engine/EngineTypes.h"
#include "ESDIGPU.h"
#include "Engine/Scene.h"
#include "GameplayTagContainer.h"
#include "Animation/PoseSnapshot.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "ESDIMathOperation.h"
#include "SDIStructuresCurvedWedgeGeometryLocationDynamicDelegateDelegate.h"
#include "SDIUtilProjectileAimAssistTargetDynamicDelegateDelegate.h"
#include "SDICollisionCacheFilterDynamicDelegateDelegate.h"
#include "UObject/NoExportTypes.h"
#include "SDIUtilRandomActorWeightDynamicDelegateDelegate.h"
#include "SDICurvedWedgeGeometry.h"
#include "SDIStructuresCurvedWedgeGeometryFilterDynamicDelegateDelegate.h"
#include "SDIStructuresCurvedWedgeGeometryBetterThanDynamicDelegateDelegate.h"
#include "SDIStructuresTargetSearchLocationDynamicDelegateDelegate.h"
#include "SDIStructuresTargetSearchFilterDynamicDelegateDelegate.h"
#include "SDIStructuresTargetSearchBetterThanDynamicDelegateDelegate.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "SDIMotionHistory.h"
#include "Engine/EngineTypes.h"
#include "RFloatExp.h"
#include "RVectorExp.h"
#include "SDIUtil.generated.h"

class UPhysicsConstraintComponent;
class UTexture2D;
class UPrimitiveComponent;
class UUserWidget;
class UActorComponent;
class APlayerState;
class USceneComponent;
class USplineComponent;
class AActor;
class UFXSystemComponent;
class USDICoreAssetDatabase;
class UFXSystemAsset;
class USDIGameSingleton;
class UObject;
class USDIObjectPoolManager;
class UChildActorComponent;
class UNavigationQueryFilter;
class APawn;
class ULevel;
class UCurveFloat;
class AGameMode;
class UWorld;
class USkeletalMeshComponent;
class UPhysicalMaterial;
class ULocalPlayer;
class APlayerController;
class APlayerCameraManager;
class UGameInstance;
class AController;
class UCapsuleComponent;

UCLASS(BlueprintType)
class SDICOREPLUGIN_API USDIUtil : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USDIUtil();
    UFUNCTION(BlueprintCallable)
    static UTexture2D* WidgetToTexture(const UUserWidget* Widget, const FVector2D& DrawSize, UTexture2D* Target, float Scale);
    
    UFUNCTION(BlueprintPure)
    static bool WasComponentRecentlyRendered(const UPrimitiveComponent* PrimComp, float Tolerance);
    
    UFUNCTION(BlueprintPure)
    static FVector VRLerp(FVector A, FVector B, float Interp, FVector Pivot);
    
    UFUNCTION(BlueprintCallable)
    static bool UpdatePhysicsConstraintTransforms(UPhysicsConstraintComponent* Constraint, const FTransform& Body1Transform, const FTransform& Body2Transform);
    
    UFUNCTION(BlueprintCallable)
    static bool TraceTransformShape(FHitResult& OutHit, const FSDITransformCollisionShape& Shape, const FVector& TraceStart, const FVector& TraceEnd);
    
    UFUNCTION(BlueprintCallable)
    static bool TraceShape(FHitResult& OutHit, const FTransform& ShapeTransform, const FSDICollisionShape& Shape, const FVector& TraceStart, const FVector& TraceEnd);
    
    UFUNCTION(BlueprintCallable)
    static bool TraceActor(AActor* Actor, FHitResult& OutHit, const FVector& Start, const FVector& End, const TArray<TEnumAsByte<ECollisionChannel>>& TraceChannels, const TArray<TEnumAsByte<ECollisionResponse>>& Responses, bool bTraceComplex, bool bReturnPhysicalMaterial, bool bFindClosest);
    
    UFUNCTION(BlueprintCallable)
    static void TeleportToAtWorldTransform(USceneComponent* Root, FTransform DesiredTransform, FTransform WorldTransform, USceneComponent* TransformComp, FTransform TransformCompRelativeTransform);
    
    UFUNCTION(BlueprintCallable)
    static bool SweepTransformShapes(FHitResult& OutHit, const FSDITransformCollisionShape& Shape, const FVector& SweepStart, const FVector& SweepEnd, const FSDITransformCollisionShape& SweepShape);
    
    UFUNCTION(BlueprintCallable)
    static bool SweepShapes(FHitResult& OutHit, const FTransform& ShapeTransform, const FSDICollisionShape& Shape, const FVector& SweepStart, const FVector& SweepEnd, const FQuat& SweepShapeRotation, const FSDICollisionShape& SweepShape);
    
    UFUNCTION(BlueprintCallable)
    static bool SweepActor(AActor* Actor, FHitResult& OutHit, const FVector& Start, const FVector& End, const FSDICollisionShape& Shape, FRotator ShapeRotation, const TArray<TEnumAsByte<ECollisionChannel>>& TraceChannels, const TArray<TEnumAsByte<ECollisionResponse>>& Responses, bool bTraceComplex, bool bFindClosest);
    
    UFUNCTION(BlueprintCallable)
    static float SplineConvertInputKeyToDistance(const USplineComponent* Spline, float InputKey);
    
    UFUNCTION(BlueprintCallable)
    static UFXSystemComponent* SpawnFXAttached(UFXSystemAsset* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, FVector Scale, TEnumAsByte<EAttachLocation::Type> LocationType, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UFXSystemComponent* SpawnFXAtLocation(const UObject* WorldContextObject, UFXSystemAsset* EmitterTemplate, FVector Location, FRotator Rotation, FVector Scale, bool bAutoDestroy, EPSCPoolMethod PoolingMethod, bool bAutoActivate);
    
    UFUNCTION(BlueprintCallable)
    static UObject* SpawnAttachment(UObject* Object, USceneComponent* Parent, const FTransform& RelativeTransform, FName SocketName);
    
    UFUNCTION(BlueprintCallable)
    static bool SetupPhysicsConstraint(UPhysicsConstraintComponent* Constraint, UPrimitiveComponent* Component1, FName BoneName1, const FTransform& Body1Transform, UPrimitiveComponent* Component2, FName BoneName2, const FTransform& Body2Transform, bool bReverseConstraint);
    
    UFUNCTION(BlueprintCallable)
    static bool SetInterpCurveVectorFromSplineComponent(FInterpCurveVector& OutSpline, const USplineComponent* SplineComp, TEnumAsByte<ESplineCoordinateSpace::Type> CoordinateSpace, int32 Resolution, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints);
    
    UFUNCTION(BlueprintCallable)
    static void SetInterpCurveVectorFromControlPointsWithTransform(FInterpCurveVector& OutSpline, const FTransform& RelativeToWorld, const TArray<FVector>& Points, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints);
    
    UFUNCTION(BlueprintCallable)
    static void SetInterpCurveVectorFromControlPoints(FInterpCurveVector& OutSpline, const TArray<FVector>& Points, float Tension, TEnumAsByte<EInterpCurveMode> CurveMode, bool bNormalizeRange, bool bStationaryEndPoints);
    
    UFUNCTION(BlueprintCallable)
    static void SetFXAutoDestroy(UFXSystemComponent* FX, bool bAutoDestroy);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static int32 ScanCollisionSphere(UObject* WorldContextObject, TEnumAsByte<ECollisionChannel> TraceChannel, TArray<FHitResult>& ArcImpactInfo, int32& NearestIndex, const TArray<AActor*>& ActorsToIgnore, const FVector& Origin, FVector BaseVector, FVector Axis, int32 NumChecks, int32 NumRings, float MaxDist, FVector Extent, bool bClipToNearest, bool bDebug);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static int32 ScanCollisionAxis(UObject* WorldContextObject, TEnumAsByte<ECollisionChannel> TraceChannel, TArray<FHitResult>& ArcImpactInfo, int32& NearestIndex, const TArray<AActor*>& ActorsToIgnore, const FVector& Origin, FVector BaseVector, FVector Axis, int32 NumChecks, float MaxDist, FVector Extent, bool bClipToNearest, bool bDebug, bool bSkipBaseVectors);
    
    UFUNCTION(BlueprintPure)
    static bool RuntimeFloatCurveHasData(const FRuntimeFloatCurve& Curve);
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* ResolveComponentReference(const FComponentReference& Reference, AActor* OwnerActor, bool bRecurseIntoParent);
    
    UFUNCTION(BlueprintCallable)
    static void RefineHitResultPhysMaterial(UPARAM(Ref) FHitResult& HitResult);
    
    UFUNCTION(BlueprintCallable)
    static void RecreatePhysicsConstraintsOnActor(AActor* Actor, UPrimitiveComponent* OtherComp);
    
    UFUNCTION(BlueprintCallable)
    static void RecreatePhysicsConstraintsOn(UPrimitiveComponent* Comp);
    
    UFUNCTION(BlueprintCallable)
    static bool RecreatePhysicsConstraint(UPhysicsConstraintComponent* Constraint);
    
    UFUNCTION(BlueprintPure)
    static bool PointInsideCollisionShape(const FVector& Point, const FSDICollisionShape& Shape, const FTransform& ShapeTransform);
    
    UFUNCTION(BlueprintCallable)
    static void OverridePostProcessSettings(UPARAM(Ref) FPostProcessSettings& Dest, const FPostProcessSettings& Src, bool bSetOverrides, bool bClearOverrides);
    
    UFUNCTION(BlueprintCallable)
    static bool OverlapTransformShapes(const FSDITransformCollisionShape& ShapeA, const FSDITransformCollisionShape& ShapeB);
    
    UFUNCTION(BlueprintCallable)
    static bool OverlapShapes(const FTransform& ShapeTransformA, const FSDICollisionShape& ShapeA, const FTransform& ShapeTransformB, const FSDICollisionShape& ShapeB);
    
    UFUNCTION(BlueprintCallable)
    static bool OverlapActor(AActor* Actor, const FSDITransformCollisionShape& Shape, const TArray<TEnumAsByte<ECollisionChannel>>& TraceChannels, const TArray<TEnumAsByte<ECollisionResponse>>& Responses);
    
    UFUNCTION(BlueprintCallable)
    static int32 OptimizeChildActorComponents(AActor* Actor, bool bDestroyComponents, bool bIncludeFromChildActors);
    
    UFUNCTION(BlueprintCallable)
    static bool OptimizeChildActorComponent(UChildActorComponent* Comp, bool bDestroyComponent);
    
    UFUNCTION(BlueprintPure)
    static bool NotHasAnyTags(const FGameplayTagContainer& TagContainer, const FGameplayTagContainer& OtherContainer, bool bExactMatch);
    
    UFUNCTION(BlueprintPure)
    static bool NotHasAllTags(const FGameplayTagContainer& TagContainer, const FGameplayTagContainer& OtherContainer, bool bExactMatch);
    
    UFUNCTION(BlueprintPure)
    static bool NotEqual_ClassClassOrSubclass(UClass* A, UClass* B, bool bACanBeSubclassOfB);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool NavigationRaycast(UObject* WorldContextObject, const FVector& RayStart, const FVector& RayEnd, FVector& HitLocation, const FNavAgentProperties& AgentPropsToUse, TSubclassOf<UNavigationQueryFilter> FilterClass);
    
    UFUNCTION()
    static bool MoveActorToPersistentLevel(AActor* Act, bool bIncludeOwnedChildren);
    
    UFUNCTION()
    static bool MoveActorToLevel(AActor* Act, ULevel* Level, bool bIncludeOwnedChildren);
    
    UFUNCTION(BlueprintPure)
    static FVector LerpVectorArray(const TArray<FVector>& Array, float Alpha, bool bIntegralElements);
    
    UFUNCTION(BlueprintPure)
    static FTransform LerpTransformArray(const TArray<FTransform>& Array, float Alpha, bool bIntegralElements);
    
    UFUNCTION(BlueprintPure)
    static FPredictProjectilePathPointData LerpProjectilePathPointArray(const TArray<FPredictProjectilePathPointData>& Array, float Alpha, bool bIntegralElements);
    
    UFUNCTION(BlueprintCallable)
    static void LerpPostProcessSettingsArr(UPARAM(Ref) FPostProcessSettings& Dest, const TArray<FPostProcessSettings>& Arr, float Alpha, bool bSetOverrides, bool bClearOverrides);
    
    UFUNCTION(BlueprintCallable)
    static void LerpPostProcessSettings(UPARAM(Ref) FPostProcessSettings& Dest, const FPostProcessSettings& A, const FPostProcessSettings& B, float Alpha, bool bSetOverrides, bool bClearOverrides);
    
    UFUNCTION(BlueprintPure)
    static float LerpIndexHelper(int32& OutIndex0, int32& OutIndex1, int32 Num, float Alpha, bool bIntegralElements);
    
    UFUNCTION(BlueprintPure)
    static float LerpFloatArray(const TArray<float>& Array, float Alpha, bool bIntegralElements);
    
    UFUNCTION(BlueprintPure)
    static bool K2IsValidClass(UClass* SearchClass, const TArray<UClass*>& ValidClasses, const TArray<UClass*>& InvalidClasses);
    
    UFUNCTION(BlueprintCallable)
    static int32 K2GetWeightedRandomIndex(const TArray<float>& Weights, const TArray<int32>& IgnoredIndices);
    
    UFUNCTION(BlueprintCallable)
    static int32 K2GetWeightedIndex(float WeightedChoice, const TArray<float>& Weights, const TArray<int32>& IgnoredIndices);
    
    UFUNCTION(BlueprintCallable)
    static int32 K2GetRandomActorsWeightedByDistanceFromSelected(int32 NumActors, TArray<AActor*>& SelectedActors, const TArray<AActor*>& ActorPool, ESDIMathOperation DistanceWeightMathOp, bool bUse2DDistance, bool bInvertWeight);
    
    UFUNCTION(BlueprintPure)
    static USDICoreAssetDatabase* K2GetAssetDatabase();
    
    UFUNCTION(BlueprintPure)
    static FHitResult K2ConvertHitResultToWorld(const FHitResult& HitResult, bool bIncludeTraceStartEnd);
    
    UFUNCTION(BlueprintPure)
    static FHitResult K2ConvertHitResultToLocal(const FHitResult& HitResult, bool bIncludeTraceStartEnd);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FVector K2ComputeProjectileAimAssistance(UObject* WorldContextObject, const FSDIUtilProjectileAimAssistTargetDynamicDelegate& TargetDelegate, const FSDICollisionCacheFilterDynamicDelegate& FilterDelegate, const FVector& StartLocation, const FVector& InitialVelocity, const TArray<AActor*>& ActorsToIgnore, TEnumAsByte<ECollisionChannel> CollisionChannel, float PathCollisionRadius, float PathCollisionTime, float TargetRadius, const UCurveFloat* TargetRadiusCurve, float TargetZOffset, const UCurveFloat* TargetZOffsetCurve, float MinResultSpeed, bool bAdjustForTargetVelocity, float DebugRenderTime);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsValidGameMode(const UObject* WorldContextObject, const TArray<TSubclassOf<AGameMode>>& ValidGameModes, const TArray<TSubclassOf<AGameMode>>& InvalidGameModes);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsPlayInEditor(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPhysicsConstraintAttachedTo(UPhysicsConstraintComponent* Constraint, const UPrimitiveComponent* Component, FName BoneName);
    
    UFUNCTION(BlueprintPure)
    static bool IsObjectChildOf(const UObject* Object, const TArray<UClass*>& Classes, bool bExact);
    
    UFUNCTION(BlueprintPure)
    static bool IsLocallyControlledActor(AActor* Actor, bool bAllowAutonomousRoles);
    
    UFUNCTION(BlueprintPure)
    static bool IsInFieldOfView(const FTransform& CameraTransform, const FVector& Location, float MaxHorizontalAngleDeg, float MaxVerticalAngleDeg);
    
    UFUNCTION(BlueprintPure)
    static bool IsClassChildOf(const UClass* Class, const TArray<UClass*>& Classes, bool bExact);
    
    UFUNCTION(BlueprintPure)
    static bool InVRMode();
    
    UFUNCTION(BlueprintPure)
    static float InverseLerpIndexHelper(int32 Index0, int32 Num, float SubAlpha);
    
    UFUNCTION(BlueprintPure)
    static bool HasLosToPoint(const AActor* Eyes, const FVector& TargetPos, const AActor* Target, bool bSimple, TEnumAsByte<ECollisionChannel> Channel);
    
    UFUNCTION(BlueprintPure)
    static bool HasLosToActor(const AActor* Eyes, const AActor* Target, bool bSimple, TEnumAsByte<ECollisionChannel> Channel);
    
    UFUNCTION(BlueprintPure)
    static bool HasLosPointToPoint(const FVector& EyePos, const FVector& TargetPos, const AActor* Eyes, const AActor* Target, TEnumAsByte<ECollisionChannel> Channel);
    
    UFUNCTION(BlueprintPure)
    static bool HasFXCompleted(UFXSystemComponent* FX);
    
    UFUNCTION(BlueprintPure)
    static bool HasAuthority(const UObject* Obj);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UWorld* GetWorldFromContextObject(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static float GetVolumetricLight(const UObject* WorldContextObject, const FVector& Position);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetTransientID();
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float GetServerTimestamp(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static USDIObjectPoolManager* GetSDIObjectPoolManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static TArray<FString> GetScalabilityQualityLevelStrings();
    
    UFUNCTION(BlueprintPure)
    static float GetRuntimeFloatCurveValue(const FRuntimeFloatCurve& Curve, float InTime);
    
    UFUNCTION(BlueprintPure)
    static bool GetRefPoseTransform(FTransform& OutTransform, USkeletalMeshComponent* SkelMeshComp, FName SocketName, TEnumAsByte<ERelativeTransformSpace> TransformSpace);
    
    UFUNCTION(BlueprintPure)
    static FTransform GetRefPoseBoneTransform(USkeletalMeshComponent* SkelMesh, FName BoneName);
    
    UFUNCTION(BlueprintPure)
    static UPhysicalMaterial* GetRefinedHitResultPhysMaterial(const FHitResult& HitResult);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float GetRealDeltaSeconds(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetRandomActors(int32 NumActors, TArray<AActor*>& SelectedActors, const TArray<AActor*>& ActorPool, FSDIUtilRandomActorWeightListDynamicDelegate WeightDelegate);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetRandomActorIndices(int32 NumActors, TArray<int32>& Indices, const TArray<AActor*>& ActorPool, FSDIUtilRandomActorWeightDynamicDelegate WeightDelegate);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetRandomActorIndex(const TArray<AActor*>& ActorPool, FSDIUtilRandomActorWeightDynamicDelegate WeightDelegate);
    
    UFUNCTION(BlueprintCallable)
    static FString GetProjectDeviceProfileNameOverride();
    
    UFUNCTION(BlueprintPure)
    static bool GetPoseSnapshotTransform(const FPoseSnapshot& Snapshot, const USkeletalMeshComponent* SkelMeshComp, FName SocketName, FTransform& OutTransform, TEnumAsByte<ERelativeTransformSpace> TransformSpace);
    
    UFUNCTION(BlueprintPure)
    static APlayerState* GetPlayerState(const UObject* Obj);
    
    UFUNCTION(BlueprintPure)
    static int32 GetPlatformMobileHiSpec();
    
    UFUNCTION(BlueprintPure)
    static float GetPingMs(const UObject* Obj);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UFXSystemAsset* GetOverrideEmitterTemplate(const UObject* WorldContextObject, UFXSystemAsset* EmitterTemplate);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetNearestSurface(UObject* WorldContextObject, FHitResult& OutSurface, TEnumAsByte<ECollisionChannel> TraceChannel, const TArray<AActor*>& ActorsToIgnore, const FVector& Origin, float Distance, FVector Extent, FVector BaseVector, FVector Axis, int32 NumChecks, int32 NumRings);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static APlayerController* GetLocalPlayerController(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static APlayerCameraManager* GetLocalPlayerCameraManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ULocalPlayer* GetLocalPlayer(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool GetGround(UObject* WorldContextObject, FHitResult& OutGround, TEnumAsByte<ECollisionChannel> TraceChannel, const TArray<AActor*>& ActorsToIgnore, const FVector& Origin, float Distance, FVector Extent);
    
    UFUNCTION(BlueprintPure)
    static ESDIGPU GetGPU();
    
    UFUNCTION(BlueprintPure)
    static int32 GetGoreLevel();
    
    UFUNCTION(BlueprintPure)
    static USDIGameSingleton* GetGameSingleton();
    
    UFUNCTION(BlueprintPure)
    static int32 GetGameplayPlatformLevel();
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UGameInstance* GetGameInstanceFromContextObject(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static int32 GetAudioPlatformLevel();
    
    UFUNCTION(BlueprintCallable)
    static void ForceNetUpdate(UObject* Obj);
    
    UFUNCTION(BlueprintCallable)
    static void ForceGarbageCollection(bool bFullPurge);
    
    UFUNCTION(BlueprintPure)
    static FString FloatToString(float Value, int32 Decimals);
    
    UFUNCTION(BlueprintPure)
    static float FloatMath(ESDIMathOperation Op, float A, float B);
    
    UFUNCTION(BlueprintPure)
    static TArray<float> FloatArrMathSingle(ESDIMathOperation Op, const TArray<float>& A, float B);
    
    UFUNCTION(BlueprintPure)
    static TArray<float> FloatArrMathMulti(ESDIMathOperation Op, const TArray<float>& A, const TArray<float>& B, bool bIntegralElements);
    
    UFUNCTION(BlueprintPure)
    static float FloatArrMath(ESDIMathOperation Op, const TArray<float>& Floats, int32& OutIndex);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsOverlapWedgeNoDelegates(TArray<FSDITargetSearchEntry>& OutTargets, const AActor* Searcher, const FTransform& SearchTransform, const FSDICurvedWedgeGeometry& SearchWedge, TEnumAsByte<ECollisionChannel> OverlapChannel, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsOverlapWedge(TArray<FSDITargetSearchEntry>& OutTargets, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDICurvedWedgeGeometry& SearchWedge, FSDIStructuresCurvedWedgeGeometryLocationDynamicDelegate LocationDelegate, FSDIStructuresCurvedWedgeGeometryFilterDynamicDelegate FilterDelegate, FSDIStructuresCurvedWedgeGeometryBetterThanDynamicDelegate BetterThanDelegate, TEnumAsByte<ECollisionChannel> OverlapChannel, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsOverlapSingleShapeNoDelegates(UPARAM(Ref) TArray<FSDITargetSearchEntry>& OutTargets, const AActor* Searcher, const FTransform& SearchTransform, const FSDITransformCollisionShape& Shape, bool bRelativeShapeTransform, TEnumAsByte<ECollisionChannel> OverlapChannel, FRotator HalfArcAngles, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsOverlapSingleShape(UPARAM(Ref) TArray<FSDITargetSearchEntry>& OutTargets, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDITransformCollisionShape& Shape, FSDIStructuresTargetSearchLocationDynamicDelegate LocationDelegate, FSDIStructuresTargetSearchFilterDynamicDelegate FilterDelegate, FSDIStructuresTargetSearchBetterThanDynamicDelegate BetterThanDelegate, bool bRelativeShapeTransform, TEnumAsByte<ECollisionChannel> OverlapChannel, FRotator HalfArcAngles, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsOverlapDualShapeNoDelegates(UPARAM(Ref) TArray<FSDITargetSearchEntry>& OutTargets, const AActor* Searcher, const FTransform& SearchTransform, const FSDITransformCollisionShape& InnerShape, const FSDITransformCollisionShape& OuterShape, bool bRelativeInnerShapeTransform, bool bRelativeOuterShapeTransform, TEnumAsByte<ECollisionChannel> OverlapChannel, FRotator HalfArcAngles, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsOverlapDualShape(UPARAM(Ref) TArray<FSDITargetSearchEntry>& OutTargets, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDITransformCollisionShape& InnerShape, const FSDITransformCollisionShape& OuterShape, FSDIStructuresTargetSearchLocationDynamicDelegate LocationDelegate, FSDIStructuresTargetSearchFilterDynamicDelegate FilterDelegate, FSDIStructuresTargetSearchBetterThanDynamicDelegate BetterThanDelegate, bool bRelativeInnerShapeTransform, bool bRelativeOuterShapeTransform, TEnumAsByte<ECollisionChannel> OverlapChannel, FRotator HalfArcAngles, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsInPoolWedgeNoDelegates(TArray<FSDITargetSearchEntry>& OutTargets, const TArray<AActor*>& TargetPool, const AActor* Searcher, const FTransform& SearchTransform, const FSDICurvedWedgeGeometry& SearchWedge, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsInPoolWedge(TArray<FSDITargetSearchEntry>& OutTargets, const TArray<AActor*>& TargetPool, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDICurvedWedgeGeometry& SearchWedge, FSDIStructuresCurvedWedgeGeometryLocationDynamicDelegate LocationDelegate, FSDIStructuresCurvedWedgeGeometryFilterDynamicDelegate FilterDelegate, FSDIStructuresCurvedWedgeGeometryBetterThanDynamicDelegate BetterThanDelegate, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsInPoolSingleShapeNoDelegates(UPARAM(Ref) TArray<FSDITargetSearchEntry>& OutTargets, const TArray<AActor*>& TargetPool, const AActor* Searcher, const FTransform& SearchTransform, const FSDITransformCollisionShape& Shape, bool bRelativeShapeTransform, FRotator HalfArcAngles, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsInPoolSingleShape(TArray<FSDITargetSearchEntry>& OutTargets, const TArray<AActor*>& TargetPool, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDITransformCollisionShape& Shape, FSDIStructuresTargetSearchLocationDynamicDelegate LocationDelegate, FSDIStructuresTargetSearchFilterDynamicDelegate FilterDelegate, FSDIStructuresTargetSearchBetterThanDynamicDelegate BetterThanDelegate, bool bRelativeShapeTransform, FRotator HalfArcAngles, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsInPoolDualShapeNoDelegates(UPARAM(Ref) TArray<FSDITargetSearchEntry>& OutTargets, const TArray<AActor*>& TargetPool, const AActor* Searcher, const FTransform& SearchTransform, const FSDITransformCollisionShape& InnerShape, const FSDITransformCollisionShape& OuterShape, bool bRelativeInnerShapeTransform, bool bRelativeOuterShapeTransform, FRotator HalfArcAngles, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintCallable)
    static int32 FindTargetsInPoolDualShape(TArray<FSDITargetSearchEntry>& OutTargets, const TArray<AActor*>& TargetPool, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDITransformCollisionShape& InnerShape, const FSDITransformCollisionShape& OuterShape, FSDIStructuresTargetSearchLocationDynamicDelegate LocationDelegate, FSDIStructuresTargetSearchFilterDynamicDelegate FilterDelegate, FSDIStructuresTargetSearchBetterThanDynamicDelegate BetterThanDelegate, bool bRelativeInnerShapeTransform, bool bRelativeOuterShapeTransform, FRotator HalfArcAngles, bool bRequireLOS, TEnumAsByte<ECollisionChannel> LosChannel, bool bSort, bool bUseClosestLocation, float DebugRenderDuration);
    
    UFUNCTION(BlueprintPure)
    static FName FindRootmostBone(const USkeletalMeshComponent* Mesh, const TArray<FName>& BoneNames);
    
    UFUNCTION(BlueprintPure)
    static FName FindRigidBodyBone(const USkeletalMeshComponent* Mesh, FName SocketName);
    
    UFUNCTION(BlueprintPure)
    static bool FindInstigatorInfo(const UObject* Object, AController*& OutController, APawn*& OutPawn);
    
    UFUNCTION(BlueprintPure)
    static AController* FindInstigatorController(const UObject* Object);
    
    UFUNCTION(BlueprintPure)
    static APawn* FindInstigator(const UObject* Object);
    
    UFUNCTION(BlueprintPure)
    static int32 FindClosestBoneMatch(FName BoneName, const USkeletalMeshComponent* Mesh, const TArray<FName>& BoneNames, bool bExact);
    
    UFUNCTION(BlueprintPure)
    static int32 FindClassMatch(UClass* SearchClass, const TArray<UClass*>& ClassArr, bool bExact);
    
    UFUNCTION(BlueprintCallable)
    static USceneComponent* FindChildComponent(const FName& ChildComponentName, USceneComponent* Parent);
    
    UFUNCTION(BlueprintPure)
    static bool EqualEqual_ClassClassOrSubclass(UClass* A, UClass* B, bool bACanBeSubclassOfB);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugTransformShape(const UObject* WorldContextObject, const FSDITransformCollisionShape& InShape, FLinearColor Color, bool bPersistent, float LifeTime, int32 SphereSegments);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugSimpleSphere(const UObject* WorldContextObject, const FVector& Center, float Radius, FLinearColor Color, bool bPersistentLines, float LifeTime);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugShape(const UObject* WorldContextObject, const FSDICollisionShape& InShape, const FVector& Location, const FRotator& Rotation, FLinearColor Color, bool bPersistent, float LifeTime, int32 SphereSegments);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugProjectilePathResult(const UObject* WorldContextObject, const FPredictProjectilePathResult& inPredictResult, FLinearColor Color, bool bPersistent, float LifeTime);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugProjectilePath(const UObject* WorldContextObject, const FVector& Start, const FVector& Velocity, float Time, TEnumAsByte<ECollisionChannel> TraceChannel, const TArray<AActor*>& ActorsToIgnore, FLinearColor Color, bool bPersistent, float LifeTime);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugMotionHistory(const UObject* WorldContextObject, const FSDIMotionHistory& History, float Timespan, float StartTimeOffset, FLinearColor Color, bool bRotation, bool bPersistent, float LifeTime, float Thickness);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugInterpCurveVectorRel(const UObject* WorldContextObject, const FInterpCurveVector& Spline, FTransform RelativeToWorld, const int32 Segments, FLinearColor Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugInterpCurveVectorPairRel(const UObject* WorldContextObject, const FInterpCurveVector& Bottom, const FInterpCurveVector& Top, FTransform RelativeToWorld, const int32 Segments, const int32 CrossSegmentInterval, FLinearColor BottomColor, FLinearColor TopColor, FLinearColor CrossSegmentColor, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness, float CrossSegmentThickness);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugInterpCurveVectorPair(const UObject* WorldContextObject, const FInterpCurveVector& Bottom, const FInterpCurveVector& Top, const int32 Segments, const int32 CrossSegmentInterval, FLinearColor BottomColor, FLinearColor TopColor, FLinearColor CrossSegmentColor, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness, float CrossSegmentThickness);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugInterpCurveVector(const UObject* WorldContextObject, const FInterpCurveVector& Spline, const int32 Segments, FLinearColor Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DrawDebugHitResult(const UObject* WorldContextObject, const FHitResult& HitResult, bool bPersistent, float LifeTime);
    
    UFUNCTION(BlueprintCallable)
    static void DrawDebugBodiesByName(UPrimitiveComponent* Component, const TArray<FName>& BodyNames, FLinearColor Color, bool bPersistent, float LifeTime, int32 SphereSegments);
    
    UFUNCTION(BlueprintCallable)
    static void DrawDebugBodies(UPrimitiveComponent* Component, bool bPersistent, float LifeTime, int32 SphereSegments);
    
    UFUNCTION(BlueprintPure)
    static float DotProductToLinear(float DotP);
    
    UFUNCTION(BlueprintPure)
    static float DotProductToExp(float DotP, float Exp);
    
    UFUNCTION(BlueprintPure)
    static float DistanceToCollisionShape(const FVector& Point, const FSDICollisionShape& Shape, const FTransform& ShapeTransform);
    
    UFUNCTION(BlueprintPure)
    static float DistanceBetweenCapsules(const UCapsuleComponent* CapA, const UCapsuleComponent* CapB);
    
    UFUNCTION(BlueprintCallable)
    static FTimerHandle DestroyActorNextFrame(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static FVector DeltaQuatToAngularVel(const FQuat& DeltaQuat, float DeltaSeconds);
    
    UFUNCTION(BlueprintPure)
    static FVector DefaultTargetSearchLocationDynamicDelegate(const AActor* Actor, const UPrimitiveComponent* PrimComp, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDITransformCollisionShape& InnerShape, const FSDITransformCollisionShape& OuterShape, bool bUseClosestLocation);
    
    UFUNCTION(BlueprintPure)
    static bool DefaultTargetSearchFilterDynamicDelegate(const AActor* Actor, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDITransformCollisionShape& InnerShape, const FSDITransformCollisionShape& OuterShape);
    
    UFUNCTION(BlueprintPure)
    static bool DefaultTargetSearchBetterThanDynamicDelegate(const FSDITargetSearchEntry& Entry, const FSDITargetSearchEntry& Other, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDITransformCollisionShape& InnerShape, const FSDITransformCollisionShape& OuterShape);
    
    UFUNCTION(BlueprintPure)
    static FVector DefaultCurvedWedgeGeometryLocationDynamicDelegate(const AActor* Actor, const UPrimitiveComponent* PrimComp, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDICurvedWedgeGeometry& SearchWedge, bool bUseClosestLocation);
    
    UFUNCTION(BlueprintPure)
    static bool DefaultCurvedWedgeGeometryFilterDynamicDelegate(const AActor* Actor, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDICurvedWedgeGeometry& SearchWedge);
    
    UFUNCTION(BlueprintPure)
    static bool DefaultCurvedWedgeGeometryBetterThanDynamicDelegate(const FSDITargetSearchEntry& Entry, const FSDITargetSearchEntry& Other, const AActor* Searcher, const UObject* SearchData, const FTransform& SearchTransform, const FSDICurvedWedgeGeometry& SearchWedge);
    
    UFUNCTION(BlueprintPure)
    static bool DebugCheatsAllowed();
    
    UFUNCTION(BlueprintPure)
    static FRotator CreateLookatRotation(FVector Direction, FRotator CurrentRotation, FVector UpHint, bool bForceUp);
    
    UFUNCTION(BlueprintCallable)
    static void CopyRenderSettingsToComponent(UPrimitiveComponent* DestComp, const UPrimitiveComponent* SrcComp);
    
    UFUNCTION(BlueprintCallable)
    static void CopyRenderSettingsToActor(AActor* DestActor, const UPrimitiveComponent* SrcComp);
    
    UFUNCTION(BlueprintPure)
    static FVector ComputeNewVelocity(FVector CurrentVelocity, FVector DesiredVelocity, float DeltaTime, float Accel, float Decel, float RotationSpeedDeg);
    
    UFUNCTION(BlueprintCallable)
    static int32 ComputeHierarchyCount(USceneComponent* Root, bool bIncludeChildActors, bool bIncludeEditorOnly);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ComputeFallInfoDefaultGravity(const UObject* WorldContextObject, float Velocity, float& OutTime, float& OutDistance);
    
    UFUNCTION(BlueprintCallable)
    static void ComputeFallInfo(float Velocity, float Gravity, float& OutTime, float& OutDistance);
    
    UFUNCTION(BlueprintCallable)
    static FTransform ComputeElbowTransform(const FVector& WristLocation, const FTransform& ShoulderTransform, float UpperArmLength, float ForeArmLength, bool bRightHand, FVector DesiredElbowDirection);
    
    UFUNCTION(BlueprintCallable)
    static bool ComputeComponentMoveWithCollision(FTransform& OutTransform, UPrimitiveComponent* Comp, FVector StartLoc, FVector EndLoc, FRotator Rotation, const TArray<AActor*>& ActorsToIgnore, const TArray<UPrimitiveComponent*>& ComponentsToIgnore, int32 NumSlideIterations);
    
    UFUNCTION(BlueprintCallable)
    static int32 ComputeActorHierarchyCount(AActor* Actor, bool bIncludeChildActors, bool bIncludeEditorOnly);
    
    UFUNCTION(BlueprintCallable)
    static bool ComponentPhysicsActive(UPrimitiveComponent* Component, float MaxLinearVelocity, float MaxAngularVelocityDegrees);
    
    UFUNCTION(BlueprintCallable)
    static FName ClosestRigidBodyNameToSegment(UPrimitiveComponent* Component, const FVector& Start, const FVector& End, FVector& OutClosestPoint);
    
    UFUNCTION(BlueprintCallable)
    static FName ClosestRigidBodyName(UPrimitiveComponent* Component, const FVector& Location, FVector& OutClosestPoint);
    
    UFUNCTION(BlueprintPure)
    static FVector ClosestPointOnRay(const FVector& Point, const FVector& StartPoint, const FVector& Direction);
    
    UFUNCTION(BlueprintCallable)
    static bool ClosestPointOnPrimitiveCollisionToSegment(UPrimitiveComponent* Comp, FVector Start, FVector End, FVector& OutPoint, bool bClampToOutside);
    
    UFUNCTION(BlueprintCallable)
    static bool ClosestPointOnPrimitiveCollision(UPrimitiveComponent* Comp, FVector SearchPoint, FVector& OutPoint, bool bClampToOutside);
    
    UFUNCTION(BlueprintPure)
    static FVector ClosestPointOnCollisionShape(const FVector& Point, const FSDICollisionShape& Shape, const FTransform& ShapeTransform, bool bClampToOutside);
    
    UFUNCTION(BlueprintCallable)
    static bool ClosestPointOnActorCollision(AActor* Target, FVector SearchPoint, FVector& OutPoint, UPrimitiveComponent*& OutComp, bool bClampToOutside);
    
    UFUNCTION(BlueprintPure)
    static FVector ClosestPointAndTimeOnSegment(const FVector& Point, const FVector& StartPoint, const FVector& EndPoint, float& Time);
    
    UFUNCTION(BlueprintPure)
    static FVector ClosestPointAndTimeOnRay(const FVector& Point, const FVector& StartPoint, const FVector& Direction, float& Time);
    
    UFUNCTION(BlueprintPure)
    static bool ClampedSegmentPlaneIntersection(const FVector& StartPoint, const FVector& EndPoint, const FVector& PlaneOrigin, const FVector& PlaneNormal, FVector& OutClampedIntersection);
    
    UFUNCTION(BlueprintCallable)
    static FRotator CircularClampPitchYaw(FRotator Input, FRotator Min, FRotator Max, float ExtraRadius, float& OutTime, FRotator& OutCenter);
    
    UFUNCTION(BlueprintPure)
    static float CalculateInterpolationTime(const FTransform& StartTransform, const FTransform& EndTransform, float LocationInterpolationSpeed, float RotationInterpolationSpeedDeg);
    
    UFUNCTION(BlueprintCallable)
    static FString BuildHierarchyString(USceneComponent* Root, bool bIncludeChildActors, bool bIncludeEditorOnly);
    
    UFUNCTION(BlueprintCallable)
    static FString BuildActorHierarchyString(AActor* Actor, bool bIncludeChildActors, bool bIncludeEditorOnly);
    
    UFUNCTION(BlueprintCallable)
    static void AttachToAtWorldTransform(USceneComponent* Root, USceneComponent* Parent, FName SocketName, FTransform WorldTransform, USceneComponent* TransformComp, FTransform TransformCompRelativeTransform);
    
    UFUNCTION(BlueprintCallable)
    static void AttachToAtComponent(USceneComponent* Root, USceneComponent* Parent, FName SocketName, USceneComponent* TransformComp);
    
    UFUNCTION(BlueprintCallable)
    static FVector AngularVelToLinearVel(const FVector& AngVel, const FVector& RelativeLocation);
    
    UFUNCTION(BlueprintCallable)
    static FQuat AngularVelToDeltaQuat(const FVector& AngVel, float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable)
    static void AddRandomImpulseToAllBodiesBelow(USkeletalMeshComponent* SkelMesh, FVector ImpulseDir, FRFloatExp ConeHalfAngleDeg, FRFloatExp Impulse, FName BoneName, bool bVelChange, bool bIncludeSelf);
    
    UFUNCTION(BlueprintCallable)
    static void AddRandomAngularImpulseInRadiansToAllBodiesBelow(USkeletalMeshComponent* SkelMesh, FRVectorExp ImpulseRad, FName BoneName, bool bVelChange, bool bIncludeSelf);
    
    UFUNCTION(BlueprintCallable)
    static void AddRandomAngularImpulseInDegreesToAllBodiesBelow(USkeletalMeshComponent* SkelMesh, FRVectorExp ImpulseDeg, FName BoneName, bool bVelChange, bool bIncludeSelf);
    
    UFUNCTION(BlueprintCallable)
    static void AddAngularImpulseInRadiansToAllBodiesBelow(USkeletalMeshComponent* SkelMesh, FVector ImpulseRad, FName BoneName, bool bVelChange, bool bIncludeSelf);
    
    UFUNCTION(BlueprintCallable)
    static void AddAngularImpulseInDegreesToAllBodiesBelow(USkeletalMeshComponent* SkelMesh, FVector ImpulseDeg, FName BoneName, bool bVelChange, bool bIncludeSelf);
    
    UFUNCTION(BlueprintCallable)
    static bool ActorPhysicsActive(AActor* Actor, UPrimitiveComponent*& ActiveComponent, float MaxLinearVelocity, float MaxAngularVelocityDegrees);
    
};

