#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "RFloat.h"
#include "TWDBTS_SetAxemanRanges.generated.h"

UCLASS(BlueprintType)
class TWD_API UTWDBTS_SetAxemanRanges : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FBlackboardKeySelector TargetKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FBlackboardKeySelector CanRushKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FBlackboardKeySelector CanGrenadeThrowKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FBlackboardKeySelector CanSwingKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FBlackboardKeySelector ThrowVelocityKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat SwingAcceptableZDifference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat SwingAcceptableRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat RushAcceptableZDifference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat RushAcceptableRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat ThrowAcceptableZDifference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat ThrowAcceptableRange;
    
    UTWDBTS_SetAxemanRanges();
};

