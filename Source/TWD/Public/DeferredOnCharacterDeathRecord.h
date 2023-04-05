#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "DeferredOnCharacterDeathRecord.generated.h"

class UDamageType;
class AActor;

USTRUCT(BlueprintType)
struct FDeferredOnCharacterDeathRecord {
    GENERATED_BODY()
public:
    UPROPERTY()
    TSubclassOf<UDamageType> DamageTypeClass;
    
    UPROPERTY()
    TWeakObjectPtr<AActor> DamageCauser;
    
    TWD_API FDeferredOnCharacterDeathRecord();
};

