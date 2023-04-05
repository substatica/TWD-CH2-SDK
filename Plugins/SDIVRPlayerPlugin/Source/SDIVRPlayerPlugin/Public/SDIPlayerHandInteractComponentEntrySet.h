#pragma once
#include "CoreMinimal.h"
#include "ESDIInteractRangeType.h"
#include "SDIPlayerHandInteractComponentEntry.h"
#include "SDIPlayerHandInteractComponentEntrySet.generated.h"

class USDIPlayerHandInteractComponent;
class ASDIPlayerController;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIPlayerHandInteractComponentEntrySet {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    ASDIPlayerController* Owner;
    
    UPROPERTY(Instanced, Transient)
    TMap<ESDIInteractRangeType, TWeakObjectPtr<USDIPlayerHandInteractComponent>> Components;
    
    UPROPERTY(Transient)
    TArray<FSDIPlayerHandInteractComponentEntry> Entries;
    
public:
    FSDIPlayerHandInteractComponentEntrySet();
};

