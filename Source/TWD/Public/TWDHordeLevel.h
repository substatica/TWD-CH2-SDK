#pragma once
#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "TWDHordeLevel.generated.h"

UCLASS()
class TWD_API ATWDHordeLevel : public ALevelScriptActor {
    GENERATED_BODY()
public:
    ATWDHordeLevel(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintNativeEvent)
    void OnHordeTimerComplete();
    
    UFUNCTION()
    void HordeTimerComplete();
    
};

