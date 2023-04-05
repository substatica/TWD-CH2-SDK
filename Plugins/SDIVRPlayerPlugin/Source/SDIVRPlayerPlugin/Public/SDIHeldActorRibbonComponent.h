#pragma once
#include "CoreMinimal.h"
#include "SDICoreRibbonComponent.h"
#include "SDIHeldActorRibbonComponent.generated.h"

class ASDIHeldActor;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIHeldActorRibbonComponent : public USDICoreRibbonComponent {
    GENERATED_BODY()
public:
    USDIHeldActorRibbonComponent();
    UFUNCTION(BlueprintCallable)
    static void SetAllHeldActorRibbonsActive(ASDIHeldActor* HeldActor, bool bActive, bool bAutoActivateOnly);
    
};

