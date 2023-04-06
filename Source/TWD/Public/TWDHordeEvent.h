#pragma once
#include "CoreMinimal.h"
#include "TWDWorldEvent.h"
#include "TWDHordeEvent.generated.h"

UCLASS()
class TWD_API UTWDHordeEvent : public UTWDWorldEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HordeTimerMultiplier;
    
    UTWDHordeEvent();
};

