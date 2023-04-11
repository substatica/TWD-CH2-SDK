#pragma once
#include "CoreMinimal.h"
#include "SDIPlayerHand.h"
#include "Engine/EngineTypes.h"
#include "SDIHandPoseInfo.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SDIGripInfo.h"
#include "SDIPlayerHandAdvanced.generated.h"

class UObject;
class UPrimitiveComponent;
class UActorComponent;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIPlayerHandAdvanced : public ASDIPlayerHand {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    UObject* GrabSurfaceFeedback;
    
    UPROPERTY(EditAnywhere)
    UObject* GrabClimbableSurfaceFeedback;
    
    UPROPERTY(EditAnywhere)
    UObject* TouchSurfaceFeedback;
    
    UPROPERTY(EditAnywhere)
    UObject* TouchClimbableSurfaceFeedback;
    
    UPROPERTY(EditAnywhere)
    FSDIHandPoseInfo GripSurfacePose;
    
    UPROPERTY(EditAnywhere)
    FSDIHandPoseInfo GripClimbableSurfacePose;
    
    UPROPERTY(EditDefaultsOnly)
    float GripSafetyInflation;
    
    UPROPERTY(EditDefaultsOnly)
    float ClimbingGripSafetyTimeBeforePress;
    
    UPROPERTY(EditDefaultsOnly)
    float ClimbingGripSafetyTimeAfterPress;
    
    UPROPERTY(EditDefaultsOnly)
    float GrabAndPullGripSafetyTimeBeforePress;
    
    UPROPERTY(EditDefaultsOnly)
    float GrabAndPullGripSafetyTimeAfterPress;
    
    UPROPERTY(EditDefaultsOnly)
    float SurfaceClenchFingerTraceDistance;
    
    UPROPERTY(EditDefaultsOnly)
    float SurfaceClenchDownDistance;
    
    UPROPERTY(EditDefaultsOnly)
    float SurfaceClenchDownHitClenchMinCollisionTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TEnumAsByte<ECollisionChannel> ClimbingTraceChannel;
    
    UPROPERTY(Transient)
    FHitResult LastValidWorldTouch;
    
    UPROPERTY(Transient)
    float LastValidWorldTouchTimestamp;
    
    UPROPERTY(Transient)
    FHitResult LastValidWorldClimbableTouch;
    
    UPROPERTY(Transient)
    float LastValidWorldClimbableTouchTimestamp;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<TWeakObjectPtr<UPrimitiveComponent>> ExtraWorldGripCollisionIgnorances;
    
public:
    ASDIPlayerHandAdvanced(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintPure)
    bool WorldGripPossible() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool ComputeSurfaceGrip(const FHitResult& Hit, UActorComponent*& GripComp, FTransform& OutTransform, FSDIHandPoseInfo& OutPose, float& OutClench, FSDIGripInfo& OutGripInfo, bool bRecurse) const;
    
    UFUNCTION(BlueprintPure)
    bool ClimbGripPossible() const;
    
};

