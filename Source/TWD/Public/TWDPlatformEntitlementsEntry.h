#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TWDPlatformEntitlementsEntry.generated.h"

USTRUCT(BlueprintType)
struct FTWDPlatformEntitlementsEntry : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FName> Meta_Sku_Ids;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<int32> Steam_Sku_Ids;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FName> PS4_Sku_Ids;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FName> PS5_Sku_Ids;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool UnlockedForCh2;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FString DevNotes;
    
    TWD_API FTWDPlatformEntitlementsEntry();
};

