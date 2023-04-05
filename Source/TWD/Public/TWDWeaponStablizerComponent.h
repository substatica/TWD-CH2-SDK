#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ESDIAxis.h"
#include "SDIQuatPIDController.h"
#include "TWDWeaponStablizerComponent.generated.h"

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTWDWeaponStablizerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    ESDIAxis StablizationAxis;
    
    UPROPERTY(EditDefaultsOnly)
    ESDIAxis ForwardAxis;
    
    UPROPERTY(EditDefaultsOnly)
    float MinStablizationSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float MaxStablizationSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIQuatPIDController MotionDirectionPIDController;
    
    UPROPERTY(EditDefaultsOnly)
    float TorqueScale;
    
    UPROPERTY(EditAnywhere)
    bool bEnableStablization;
    
    UTWDWeaponStablizerComponent();
};

