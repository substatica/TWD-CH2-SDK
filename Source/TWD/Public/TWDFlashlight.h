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
    
    ATWDFlashlight();
    UFUNCTION(BlueprintCallable)
    void SetUVMode(bool isUV);
    
    UFUNCTION(BlueprintCallable)
    void SetSwitchedOn(bool inSwitchedOn);
    
    UFUNCTION(BlueprintCallable)
    void SetPowered(bool inPowered);
    
    UFUNCTION(BlueprintPure)
    bool IsUVMode() const;
    
    UFUNCTION(BlueprintPure)
    bool IsSwitchedOn() const;
    
    UFUNCTION(BlueprintPure)
    bool IsPowered() const;
    
    UFUNCTION(BlueprintPure)
    bool IsOn() const;
    
};

