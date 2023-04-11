#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerCapsule.h"
#include "SDIAsyncTriggerCapsule.generated.h"

class USDIAsyncOverlapEventGeneratorComponent;

UCLASS()
class SDICOREPLUGIN_API ASDIAsyncTriggerCapsule : public ATriggerCapsule {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIAsyncOverlapEventGeneratorComponent* OverlapGenerator;
    
public:
    ASDIAsyncTriggerCapsule(const FObjectInitializer& ObjectInitializer);
};

