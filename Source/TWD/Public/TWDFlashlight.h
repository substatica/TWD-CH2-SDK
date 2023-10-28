#pragma once
#include "CoreMinimal.h"
#include "TWDProp.h"
#include "TWDFlashlight.generated.h"

UCLASS()
class TWD_API ATWDFlashlight : public ATWDProp {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    bool bInsideOnRep_bRepInsideInventory;
    
    UPROPERTY()
    bool bSwitchedOn;
    
    UPROPERTY()
    bool bPowered;
    
    UPROPERTY()
    bool bUVMode;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float PerceptionOverrideDotProductMinimum;
    
    ATWDFlashlight(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetUVMode(bool isUV);
    
    UFUNCTION(BlueprintCallable)
    void SetSwitchedOn(bool inSwitchedOn);
    
    UFUNCTION(BlueprintCallable)
    void SetPowered(bool inPowered);
    
    UFUNCTION(BlueprintCallable)
    bool IsUVMode() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsSwitchedOn() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsPowered() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsOn() const;
};

