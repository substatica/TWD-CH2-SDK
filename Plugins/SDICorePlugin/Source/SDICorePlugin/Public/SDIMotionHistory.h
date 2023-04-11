#pragma once
#include "CoreMinimal.h"
#include "SDIMotionHistoryEntry.h"
#include "SDIMotionHistory.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIMotionHistory {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    TArray<FSDIMotionHistoryEntry> Entries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxHistoryTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxHistoryEntries;
    
public:
    FSDIMotionHistory();
};

