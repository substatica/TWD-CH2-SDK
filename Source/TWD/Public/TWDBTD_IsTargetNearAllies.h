#pragma once
#include "CoreMinimal.h"
#include "TWDBTD_Base.h"
#include "TWDBTD_IsTargetNearAllies.generated.h"

UCLASS(BlueprintType)
class TWD_API UTWDBTD_IsTargetNearAllies : public UTWDBTD_Base {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxDistance;
    
public:
    UTWDBTD_IsTargetNearAllies();
};

