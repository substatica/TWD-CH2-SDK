#pragma once
#include "CoreMinimal.h"
#include "TWDProp.h"
#include "TWDGutsActor.generated.h"

class ATWDCharacter;

UCLASS()
class TWD_API ATWDGutsActor : public ATWDProp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    float SwipeAccumulator;
    
    UPROPERTY(BlueprintReadWrite)
    float SwipeDelta;
    
    UPROPERTY(EditAnywhere)
    float SwipeAmountRequired;
    
    UPROPERTY(EditAnywhere)
    float CameraTargetRadius;
    
    UPROPERTY(EditAnywhere)
    float ArmTargetRadius;
    
    UPROPERTY(EditAnywhere)
    bool bShowDebugData;
    
    UPROPERTY(BlueprintReadWrite)
    bool bIsApplying;
    
    ATWDGutsActor(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnApplied(ATWDCharacter* PlayerCharacter);
    
    UFUNCTION(BlueprintPure)
    float GetSwipeProgress() const;
    
};

