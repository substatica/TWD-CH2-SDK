#pragma once
#include "CoreMinimal.h"
#include "SDIRigidBodyImpulse.h"
#include "SDIRigidBodyRadialImpulse.h"
#include "SDIQueuedRagdoll.generated.h"

class ASDICoreCharacter;

USTRUCT(BlueprintType)
struct FSDIQueuedRagdoll {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDICoreCharacter> Character;
    
    UPROPERTY(Transient)
    FName OverrideConstraintProfileName;
    
    UPROPERTY(Transient)
    float OverrideConstraintProfileDuration;
    
    UPROPERTY(Transient)
    float PhysicalAnimationStrength;
    
    UPROPERTY(Transient)
    FName PhysicalAnimationProfileName;
    
    UPROPERTY(Transient)
    float PhysicalAnimationDuration;
    
    UPROPERTY(Transient)
    TArray<FSDIRigidBodyImpulse> Impulses;
    
    UPROPERTY(Transient)
    TArray<FSDIRigidBodyRadialImpulse> RadialImpulses;
    
    SDICOREPLUGIN_API FSDIQueuedRagdoll();
};

