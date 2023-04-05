#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIAnimInstance.h"
#include "SDIHandPoseInfo.h"
#include "InputCoreTypes.h"
#include "SDIGripInfo.h"
#include "UObject/NoExportTypes.h"
#include "SDIHandPoseAnimInstance.generated.h"

class AActor;
class UActorComponent;
class USDIControllerInputAnimInstance;
class USDIHandPoseAnimInstance;

UCLASS(NonTransient)
class SDIVRPLAYERPLUGIN_API USDIHandPoseAnimInstance : public USDIAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    EControllerHand hand;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Transient)
    bool bGripInfoValid;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Transient)
    FSDIGripInfo GripInfo;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Transient)
    float ThumbClench;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Transient)
    float PointingClench;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Transient)
    float MiddleClench;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Transient)
    float RingClench;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Transient)
    float PinkyClench;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Transient)
    FVector HandLinearOrientX;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Transient)
    FVector HandLinearOrientY;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Transient)
    FVector HandLinearOrientZ;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    AActor* PoseActor;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bGripChange;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FSDIHandPoseInfo GripChangePrevPose;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    UActorComponent* GripChangePrevGripComp;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FSDIGripInfo GripChangePrevGripInfo;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FSDIHandPoseInfo GripChangeNewPose;
    
    UPROPERTY(BlueprintReadOnly, Instanced, Transient)
    UActorComponent* GripChangeNewGripComp;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FSDIGripInfo GripChangeNewGripInfo;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    USDIControllerInputAnimInstance* MasterInst;
    
public:
    USDIHandPoseAnimInstance();
    UFUNCTION(BlueprintNativeEvent)
    void RequestGripChange(const FSDIHandPoseInfo& PrevPose, UActorComponent* PrevGripComp, const FSDIGripInfo& PrevGripInfo, const FSDIHandPoseInfo& NewPose, UActorComponent* NewGripComp, const FSDIGripInfo& NewGripInfo);
    
    UFUNCTION(BlueprintNativeEvent)
    void Initialize(USDIControllerInputAnimInstance* Master, TSubclassOf<USDIHandPoseAnimInstance> PrevInstanceClass);
    
    UFUNCTION(BlueprintNativeEvent)
    bool AllowPhysicalInteractionCollision() const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool AllowCosmeticPhysicsFingers() const;
    
};

