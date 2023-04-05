#pragma once
#include "CoreMinimal.h"
#include "GauntletTestController.h"
#include "TWDGauntletController.generated.h"

UCLASS()
class UTWDGauntletController : public UGauntletTestController {
    GENERATED_BODY()
public:
    UTWDGauntletController(const FObjectInitializer& ObjectInitializer);
private:
    UFUNCTION()
    void OnTestsRefreshed();
    
    UFUNCTION()
    void OnTestsComplete();
    
};

