#include "SDIHandPoseAnimInstance.h"
#include "Templates/SubclassOf.h"

class UActorComponent;
class USDIControllerInputAnimInstance;
class USDIHandPoseAnimInstance;

void USDIHandPoseAnimInstance::RequestGripChange_Implementation(const FSDIHandPoseInfo& PrevPose, UActorComponent* PrevGripComp, const FSDIGripInfo& PrevGripInfo, const FSDIHandPoseInfo& NewPose, UActorComponent* NewGripComp, const FSDIGripInfo& NewGripInfo) {
}

void USDIHandPoseAnimInstance::Initialize_Implementation(USDIControllerInputAnimInstance* Master, TSubclassOf<USDIHandPoseAnimInstance> PrevInstanceClass) {
}

bool USDIHandPoseAnimInstance::AllowPhysicalInteractionCollision_Implementation() const {
    return false;
}

bool USDIHandPoseAnimInstance::AllowCosmeticPhysicsFingers_Implementation() const {
    return false;
}

USDIHandPoseAnimInstance::USDIHandPoseAnimInstance() {
    this->hand = EControllerHand::AnyHand;
    this->bGripInfoValid = false;
    this->ThumbClench = 0.00f;
    this->PointingClench = 0.00f;
    this->MiddleClench = 0.00f;
    this->RingClench = 0.00f;
    this->PinkyClench = 0.00f;
    this->PoseActor = NULL;
    this->bGripChange = false;
    this->GripChangePrevGripComp = NULL;
    this->GripChangeNewGripComp = NULL;
    this->MasterInst = NULL;
}

