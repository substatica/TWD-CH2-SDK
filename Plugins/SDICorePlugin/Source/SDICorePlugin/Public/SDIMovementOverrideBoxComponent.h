#pragma once
#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "SDIMovementOverrideInterface.h"
#include "SDIMovementOverrideBoxComponent.generated.h"

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDICOREPLUGIN_API USDIMovementOverrideBoxComponent : public UBoxComponent, public ISDIMovementOverrideInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    bool bCrouch;
    
    UPROPERTY(EditAnywhere)
    bool bCrawl;
    
public:
    USDIMovementOverrideBoxComponent();
    
    // Fix for true pure virtual functions not being implemented
};

