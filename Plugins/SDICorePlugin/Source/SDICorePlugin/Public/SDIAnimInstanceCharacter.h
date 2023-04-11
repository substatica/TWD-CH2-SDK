#pragma once
#include "CoreMinimal.h"
#include "SDIAnimInstance.h"
#include "SDIAnimationHandIKTarget.h"
#include "InputCoreTypes.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDIAnimInstanceCharacter.generated.h"

class USceneComponent;

UCLASS(NonTransient)
class SDICOREPLUGIN_API USDIAnimInstanceCharacter : public USDIAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIAnimationHandIKTarget LeftHandIK;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIAnimationHandIKTarget RightHandIK;
    
public:
    USDIAnimInstanceCharacter();
    UFUNCTION(BlueprintCallable)
    void SetHandIKTransform(EControllerHand hand, const FTransform& Transform, USceneComponent* RelativeComponent, const FName& SocketName, bool bInWorldSpace);
    
    UFUNCTION(BlueprintCallable)
    void SetHandIKOnSurface(EControllerHand hand, const FHitResult& Hit, const FVector& HandHintDirection, bool bHintDirectionIsHandForward);
    
    UFUNCTION(BlueprintCallable)
    void SetHandIKDirections(EControllerHand hand, const FVector& Location, const FVector& HandForward, const FVector& HandHintDirection, bool bHintDirectionIsPalmDirection, USceneComponent* RelativeComponent, const FName& SocketName, bool bInWorldSpace);
    
    UFUNCTION(BlueprintCallable)
    void SetHandIKActive(EControllerHand hand, bool bActive, float BlendTime);
    
    UFUNCTION(BlueprintPure)
    bool IsHandIKActive(EControllerHand hand, float& OutAlpha) const;
    
    UFUNCTION(BlueprintCallable)
    void EnableHandIKEffectorSpring(EControllerHand hand, bool bEnabled);
    
};

