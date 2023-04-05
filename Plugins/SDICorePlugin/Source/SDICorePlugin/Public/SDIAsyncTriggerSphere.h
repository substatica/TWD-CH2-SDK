#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerSphere.h"
#include "SDIAsyncTriggerSphere.generated.h"

class USDIAsyncOverlapEventGeneratorComponent;

UCLASS()
class SDICOREPLUGIN_API ASDIAsyncTriggerSphere : public ATriggerSphere {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIAsyncOverlapEventGeneratorComponent* OverlapGenerator;
    
public:
    ASDIAsyncTriggerSphere(const FObjectInitializer& ObjectInitializer);
};

