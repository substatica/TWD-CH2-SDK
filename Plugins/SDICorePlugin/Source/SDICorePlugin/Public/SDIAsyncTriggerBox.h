#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "SDIAsyncTriggerBox.generated.h"

class USDIAsyncOverlapEventGeneratorComponent;

UCLASS()
class SDICOREPLUGIN_API ASDIAsyncTriggerBox : public ATriggerBox {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIAsyncOverlapEventGeneratorComponent* OverlapGenerator;
    
public:
    ASDIAsyncTriggerBox(const FObjectInitializer& ObjectInitializer);
};

