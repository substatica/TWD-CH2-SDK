#include "SDIAnimInstanceCharacter.h"

class USceneComponent;

void USDIAnimInstanceCharacter::SetHandIKTransform(EControllerHand hand, const FTransform& Transform, USceneComponent* RelativeComponent, const FName& SocketName, bool bInWorldSpace) {
}

void USDIAnimInstanceCharacter::SetHandIKOnSurface(EControllerHand hand, const FHitResult& Hit, const FVector& HandHintDirection, bool bHintDirectionIsHandForward) {
}

void USDIAnimInstanceCharacter::SetHandIKDirections(EControllerHand hand, const FVector& Location, const FVector& HandForward, const FVector& HandHintDirection, bool bHintDirectionIsPalmDirection, USceneComponent* RelativeComponent, const FName& SocketName, bool bInWorldSpace) {
}

void USDIAnimInstanceCharacter::SetHandIKActive(EControllerHand hand, bool bActive, float BlendTime) {
}

bool USDIAnimInstanceCharacter::IsHandIKActive(EControllerHand hand, float& OutAlpha) const {
    return false;
}

void USDIAnimInstanceCharacter::EnableHandIKEffectorSpring(EControllerHand hand, bool bEnabled) {
}

USDIAnimInstanceCharacter::USDIAnimInstanceCharacter() {
}

