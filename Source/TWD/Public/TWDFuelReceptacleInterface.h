#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Interface.h"
#include "TWDFuelReceptacleInterface.generated.h"

class ASDIInventoryActor;
class UObject;
class UPrimitiveComponent;

UINTERFACE(Blueprintable)
class UTWDFuelReceptacleInterface : public UInterface {
    GENERATED_BODY()
};

class ITWDFuelReceptacleInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool NeedsRefueling() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetMaxFuelAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TSubclassOf<ASDIInventoryActor> GetFuelReloadPropClass() const;
    
    UFUNCTION(BlueprintNativeEvent)
    float GetFuelPropCurrencyAmount(UObject* InventoryHolder) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetFuelPercentage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FText GetFuelName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TSubclassOf<ASDIInventoryActor> GetFuelCurrencyClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetFuelAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanBeRefueled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AttemptAddFuel(UPrimitiveComponent* HitComponent, float FuelAmount);
    
};

