#pragma once
#include "CoreMinimal.h"
#include "TWDTowerPresenceInfo.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDTowerPresenceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TArray<FName> TierSublevels;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bDaytimePresence;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bNighttimePresence;
    
    FTWDTowerPresenceInfo();
};

