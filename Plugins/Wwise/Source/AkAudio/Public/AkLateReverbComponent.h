#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AkLateReverbComponent.generated.h"

class UAkAuxBus;
class UAkLateReverbComponent;

UCLASS(BlueprintType, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AKAUDIO_API UAkLateReverbComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    uint8 bEnable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAuxBus* AuxBus;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere)
    FString AuxBusName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float SendLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FadeRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Priority;
    
    UPROPERTY(Instanced, Transient)
    UAkLateReverbComponent* NextLowerPriorityComponent;
    
    UAkLateReverbComponent();
};

