#pragma once
#include "CoreMinimal.h"
#include "TWDExileOrderBox.h"
#include "TWDExileOrderDeliveryBox.generated.h"

UCLASS()
class TWD_API ATWDExileOrderDeliveryBox : public ATWDExileOrderBox {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeliveryCompletedDelegate);
    
    UPROPERTY(BlueprintAssignable)
    FOnDeliveryCompletedDelegate OnDeliveryCompleted;
    
    ATWDExileOrderDeliveryBox();
protected:
    UFUNCTION()
    void OnDeliveryBoxOpenStateChanged();
    
public:
    UFUNCTION(BlueprintPure)
    bool IsOrderSatisfied() const;
    
    UFUNCTION(BlueprintPure)
    bool IsDeliveryComplete() const;
    
};

