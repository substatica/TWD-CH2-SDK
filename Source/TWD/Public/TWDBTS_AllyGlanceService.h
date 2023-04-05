#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "TWDBTS_AllyGlanceService.generated.h"

UCLASS(BlueprintType)
class TWD_API UTWDBTS_AllyGlanceService : public UBTService {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FBlackboardKeySelector CurrentAllyKey;
    
    UTWDBTS_AllyGlanceService();
};

