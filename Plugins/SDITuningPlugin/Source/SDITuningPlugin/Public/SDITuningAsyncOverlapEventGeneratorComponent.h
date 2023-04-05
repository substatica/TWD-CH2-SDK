#pragma once
#include "CoreMinimal.h"
#include "SDIAsyncOverlapEventGeneratorComponent.h"
#include "SDITuningAsyncOverlapEventGeneratorComponent.generated.h"

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDITUNINGPLUGIN_API USDITuningAsyncOverlapEventGeneratorComponent : public USDIAsyncOverlapEventGeneratorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere)
    bool bOnlyOverlapTuningInterface;
    
public:
    USDITuningAsyncOverlapEventGeneratorComponent();
    UFUNCTION(BlueprintCallable)
    void SetOnlyOverlapTuningInterface(bool bInOnlyOverlapTuningInterface);
    
};

