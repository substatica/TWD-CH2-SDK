#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OnAnimationActionPlayDelegateDelegate.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "SDIEnumTypeHandle.h"
#include "PlayAnimationActionCallbackProxy.generated.h"

class UPlayAnimationActionCallbackProxy;
class ATWDCharacter;
class UAnimMontage;

UCLASS(BlueprintType, MinimalAPI)
class UPlayAnimationActionCallbackProxy : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnAnimationActionPlayDelegate OnCompleted;
    
    UPROPERTY(BlueprintAssignable)
    FOnAnimationActionPlayDelegate OnBlendOut;
    
    UPROPERTY(BlueprintAssignable)
    FOnAnimationActionPlayDelegate OnInterrupted;
    
    UPROPERTY(BlueprintAssignable)
    FOnAnimationActionPlayDelegate OnNotifyBegin;
    
    UPROPERTY(BlueprintAssignable)
    FOnAnimationActionPlayDelegate OnNotifyEnd;
    
    UPlayAnimationActionCallbackProxy();
protected:
    UFUNCTION()
    void OnNotifyEndReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);
    
    UFUNCTION()
    void OnNotifyBeginReceived(FName NotifyName, const FBranchingPointNotifyPayload& BranchingPointNotifyPayload);
    
    UFUNCTION()
    void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
    
    UFUNCTION()
    void OnMontageBlendingOut(UAnimMontage* Montage, bool bInterrupted);
    
public:
    UFUNCTION(BlueprintCallable)
    static UPlayAnimationActionCallbackProxy* CreateProxyObjectForPlayAnimationAction(ATWDCharacter* InCharacter, const FSDIEnumTypeHandle& A, float PlayRate, float StartingPosition, FName StartingSection);
    
};

