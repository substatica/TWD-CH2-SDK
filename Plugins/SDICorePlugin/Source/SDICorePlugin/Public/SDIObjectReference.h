#pragma once
#include "CoreMinimal.h"
#include "SDIReferenceCounter.h"
#include "SDIObjectReference.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIObjectReference : public FSDIReferenceCounter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    UObject* Reference;
    
public:
    FSDIObjectReference();
};

