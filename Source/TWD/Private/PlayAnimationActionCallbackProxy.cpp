#include "PlayAnimationActionCallbackProxy.h"

class UPlayAnimationActionCallbackProxy;
class ATWDCharacter;
class UAnimMontage;

void UPlayAnimationActionCallbackProxy::OnNotifyEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload) {
}

void UPlayAnimationActionCallbackProxy::OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload) {
}

void UPlayAnimationActionCallbackProxy::OnMontageEnded(UAnimMontage* Montage, bool bInterrupted) {
}

void UPlayAnimationActionCallbackProxy::OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted) {
}

UPlayAnimationActionCallbackProxy* UPlayAnimationActionCallbackProxy::CreateProxyObjectForPlayAnimationAction(ATWDCharacter* InCharacter, const FSDIEnumTypeHandle& A, float PlayRate, float StartingPosition, FName StartingSection) {
    return NULL;
}

UPlayAnimationActionCallbackProxy::UPlayAnimationActionCallbackProxy() {
}

