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
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EControllerHand hand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    bool bGripInfoValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    FSDIGripInfo GripInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    float ThumbClench;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    float PointingClench;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    float MiddleClench;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    float RingClench;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    float PinkyClench;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    FVector HandLinearOrientX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    FVector HandLinearOrientY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    FVector HandLinearOrientZ;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    AActor* PoseActor;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bGripChange;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIHandPoseInfo GripChangePrevPose;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UActorComponent* GripChangePrevGripComp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIGripInfo GripChangePrevGripInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIHandPoseInfo GripChangeNewPose;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UActorComponent* GripChangeNewGripComp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDIGripInfo GripChangeNewGripInfo;
    
    UPROPERTY(BlueprintReadWrite, Transient)
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

