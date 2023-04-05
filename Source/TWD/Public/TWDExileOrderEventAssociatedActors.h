#pragma once
#include "CoreMinimal.h"
#include "TWDExileOrderEventAssociatedActors.generated.h"

class ATWDExileOrderDeliveryBox;
class ATWDExileOrderRewardBox;
class ATWDCharacter;

USTRUCT(BlueprintType)
struct FTWDExileOrderEventAssociatedActors {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    ATWDExileOrderDeliveryBox* DeliveryBox;
    
    UPROPERTY(BlueprintReadWrite)
    ATWDExileOrderRewardBox* RewardBox;
    
    UPROPERTY(BlueprintReadWrite)
    ATWDCharacter* ExileNPC;
    
    TWD_API FTWDExileOrderEventAssociatedActors();
};

