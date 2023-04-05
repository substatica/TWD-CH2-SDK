#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TWDDismemberWoundInfo.h"
#include "Engine/EngineTypes.h"
#include "TWDCharacterDelayedDismember.generated.h"

class ATWDWeaponActor;
class AController;
class UTWDWeaponHitCapsuleComponent;

USTRUCT(BlueprintType)
struct FTWDCharacterDelayedDismember : public FTWDDismemberWoundInfo {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    bool bDropLimb;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<AController> WeakInstigatorController;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ATWDWeaponActor> WeakWeapon;
    
    UPROPERTY(Instanced, Transient)
    TWeakObjectPtr<UTWDWeaponHitCapsuleComponent> WeakDismemberCapsule;
    
    UPROPERTY(Transient)
    FVector ActorSpaceImpulseDirection;
    
    UPROPERTY(Transient)
    FTimerHandle TimerHandle;
    
    UPROPERTY(Transient)
    int32 PreSeverWoundID;
    
    UPROPERTY(Transient)
    int32 ID;
    
    UPROPERTY(Transient)
    float SplayDuration;
    
    UPROPERTY(Transient)
    bool bUseAdvancedDismemberment;
    
    TWD_API FTWDCharacterDelayedDismember();
};

