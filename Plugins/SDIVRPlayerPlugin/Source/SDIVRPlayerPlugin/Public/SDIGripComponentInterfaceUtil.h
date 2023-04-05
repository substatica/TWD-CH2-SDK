#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SDIGripInfo.h"
#include "UObject/NoExportTypes.h"
#include "ESDIGripType.h"
#include "InputCoreTypes.h"
#include "ESDIGripMovement.h"
#include "SDIHandPoseInfo.h"
#include "ESDIInteractRangeType.h"
#include "SDIGripComponentInterfaceUtil.generated.h"

class UActorComponent;
class UPrimitiveComponent;
class AActor;
class USceneComponent;
class ASDIPlayerHand;
class UPhysicsConstraintComponent;

UCLASS(BlueprintType)
class SDIVRPLAYERPLUGIN_API USDIGripComponentInterfaceUtil : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USDIGripComponentInterfaceUtil();
    UFUNCTION(BlueprintPure)
    static bool UpdateGripEveryFrame(const UActorComponent* Grip, const UPrimitiveComponent* SimulatePhysicsComponent);
    
    UFUNCTION(BlueprintCallable)
    static void UpdateGripAttachmentInfos(AActor* Actor, USceneComponent* OldParent, USceneComponent* NewParent, FName NewParentSocketName);
    
    UFUNCTION(BlueprintPure)
    static FTransform K2GetTransform(const UActorComponent* Grip, FSDIGripInfo GripInfo, bool bApplyRotation);
    
    UFUNCTION(BlueprintCallable)
    static void K2AttachToAtGripComponent(USceneComponent* Root, USceneComponent* Parent, FName SocketName, const UActorComponent* Grip, FSDIGripInfo GripInfo);
    
    UFUNCTION(BlueprintPure)
    static bool IsValidForHand(const UActorComponent* Grip, const ASDIPlayerHand* hand, ESDIGripType GripType);
    
    UFUNCTION(BlueprintPure)
    static bool IsValidFor(const UActorComponent* Grip, EControllerHand hand, ESDIGripType GripType);
    
    UFUNCTION(BlueprintPure)
    static bool IsActiveGrip(const UActorComponent* Grip);
    
    UFUNCTION(BlueprintPure)
    static void GetUpdateGripThresholds(const UActorComponent* Grip, float& OutLinearDistanceUpdateThreshold, float& OutAngularDistanceUpdateThresholdDegrees);
    
    UFUNCTION(BlueprintPure)
    static FTransform GetSceneComponentTransform(const UActorComponent* Grip);
    
    UFUNCTION(BlueprintPure)
    static FTransform GetSceneComponentRelativeTransform(const UActorComponent* Grip, const FSDIGripInfo& GripInfo, const FTransform& WorldTransform);
    
    UFUNCTION(BlueprintPure)
    static USceneComponent* GetSceneComponent(const UActorComponent* Grip, FName& OutSocketName);
    
    UFUNCTION(BlueprintPure)
    static ESDIGripMovement GetRotationGripMovement(const UActorComponent* Grip);
    
    UFUNCTION(BlueprintPure)
    static ESDIGripMovement GetLocationGripMovement(const UActorComponent* Grip);
    
    UFUNCTION(BlueprintPure)
    static FSDIHandPoseInfo GetHandPoseInfo(const UActorComponent* Grip);
    
    UFUNCTION(BlueprintPure)
    static EControllerHand GetHand(const UActorComponent* Grip);
    
    UFUNCTION(BlueprintPure)
    static ESDIGripType GetGripType(const UActorComponent* Grip);
    
    UFUNCTION(BlueprintPure)
    static UPhysicsConstraintComponent* GetConstraint(const UActorComponent* Grip);
    
    UFUNCTION(BlueprintPure)
    static FTransform GetBaseTransform(const UActorComponent* Grip);
    
    UFUNCTION(BlueprintPure)
    static USceneComponent* GetAttachParent(const UActorComponent* Grip, FName& OutSocketName);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UActorComponent*> GetAllGrips(AActor* Actor, EControllerHand hand, ESDIGripType GripType, bool bActiveOnly);
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* FindBestGripForHand(const USceneComponent* ParentComp, const ASDIPlayerHand* hand, FSDIGripInfo& OutGripInfo, bool bUseTracked, ESDIGripType GripType, ESDIInteractRangeType RangeType, bool bRecurse, bool bActiveOnly, bool bApplyRotationConstraints, bool bUseDesiredGripInfo, bool bDistanceOnly);
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* FindBestGrip(const USceneComponent* ParentComp, const FTransform& HandTransform, FSDIGripInfo& OutGripInfo, EControllerHand hand, const ASDIPlayerHand* HandPtr, ESDIGripType GripType, ESDIInteractRangeType RangeType, bool bRecurse, bool bActiveOnly, bool bApplyRotationConstraints, bool bUseDesiredGripInfo, bool bDistanceOnly);
    
    UFUNCTION(BlueprintPure)
    static FTransform ComputeTransformForHand(const UActorComponent* Grip, FSDIGripInfo& OutGripInfo, const ASDIPlayerHand* hand, bool bUseTracked, bool bTwist, bool bSwing1, bool bSwing2, bool bUseDesiredGripInfo);
    
    UFUNCTION(BlueprintPure)
    static FTransform ComputeTransform(const UActorComponent* Grip, FSDIGripInfo& OutGripInfo, const FTransform& HandTransform, const ASDIPlayerHand* hand, bool bTwist, bool bSwing1, bool bSwing2, bool bUseDesiredGripInfo);
    
    UFUNCTION(BlueprintCallable)
    static float CalculateInterpolationTimeGripInfo(const UActorComponent* Grip, const FSDIGripInfo& GripInfo, const FTransform& HandTransform, float LocationInterpolationSpeed, float RotationInterpolationSpeedDeg);
    
    UFUNCTION(BlueprintCallable)
    static float CalculateInterpolationTime(const UActorComponent* Grip, const FTransform& HandTransform, float LocationInterpolationSpeed, float RotationInterpolationSpeedDeg);
    
    UFUNCTION(BlueprintCallable)
    static bool AdjustGripForHand(const UActorComponent* Grip, const ASDIPlayerHand* hand, FSDIGripInfo BaseGripInfo, FSDIGripInfo CurrentGripInfo, UPARAM(Ref) FSDIGripInfo& AdjustedGripInfo, bool bCosmetic);
    
};

