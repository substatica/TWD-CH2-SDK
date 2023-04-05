#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SDIInteractiveHighlightManager.generated.h"

class ASDIInteractiveHighlightManager;
class UObject;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIInteractiveHighlightManager : public AActor {
    GENERATED_BODY()
public:
    ASDIInteractiveHighlightManager(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ASDIInteractiveHighlightManager* GetInteractiveHighlightManager(const UObject* WorldContextObject);
    
};

