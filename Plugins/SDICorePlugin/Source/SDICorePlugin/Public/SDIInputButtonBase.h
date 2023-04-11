#pragma once
#include "CoreMinimal.h"
#include "SDIInputButtonPressedSignatureDelegate.h"
#include "SDIInputButtonReleasedSignatureDelegate.h"
#include "Engine/EngineTypes.h"
#include "SDIInputButtonLongHoldSignatureDelegate.h"
#include "SDIInputButtonBase.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIInputButtonBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DoubleTapPressTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DoubleTapReleaseTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LongHoldTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bHeld;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bDoubleTap;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DoubleTapPressedTimer;
    
    UPROPERTY(Transient)
    TArray<FSDIInputButtonPressedSignature> OnPressed;
    
    UPROPERTY(Transient)
    TArray<FSDIInputButtonReleasedSignature> OnReleased;
    
    UPROPERTY(Transient)
    TArray<FSDIInputButtonLongHoldSignature> OnLongHold;
    
    UPROPERTY(Transient)
    FTimerHandle LongHoldTimerHandle;
    
public:
    FSDIInputButtonBase();
};

