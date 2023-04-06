#pragma once
#include "CoreMinimal.h"
#include "TWDTowerPresenceInfo.generated.h"

USTRUCT(BlueprintType)
struct TWD_API FTWDTowerPresenceInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FName> TierSublevels;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDaytimePresence;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNighttimePresence;
    
    FTWDTowerPresenceInfo();
};

