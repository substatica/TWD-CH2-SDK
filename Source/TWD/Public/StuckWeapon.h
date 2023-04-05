#pragma once
#include "CoreMinimal.h"
#include "StuckWeapon.generated.h"

class UParticleSystemComponent;
class ATWDWeaponActor;

USTRUCT(BlueprintType)
struct FStuckWeapon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<ATWDWeaponActor> StuckWeapon;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UParticleSystemComponent* StabLoopPSComp;
    
    TWD_API FStuckWeapon();
};

