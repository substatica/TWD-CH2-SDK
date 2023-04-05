#pragma once
#include "CoreMinimal.h"
#include "TWDExileOrderBox.h"
#include "TWDExileOrderRewardBox.generated.h"

UCLASS()
class TWD_API ATWDExileOrderRewardBox : public ATWDExileOrderBox {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnRewardTheftDelegate);
    
    UPROPERTY(BlueprintAssignable)
    FOnRewardTheftDelegate OnRewardTheft;
    
    ATWDExileOrderRewardBox(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION()
    void OnRewardBoxOpenStateChanged();
    
public:
    UFUNCTION(BlueprintPure)
    bool IsRewardClaimed() const;
    
};

