#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/EngineTypes.h"
#include "TWDNonVRMeleeAttackHitDetails.h"
#include "UObject/NoExportTypes.h"
#include "ETWDNonVRMeleeAttackType.h"
#include "TWDNonVRMeleeAttackDetails.generated.h"

class ASDIHeldActor;

USTRUCT(BlueprintType)
struct FTWDNonVRMeleeAttackDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIHeldActor* HeldActor;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TSubclassOf<ASDIHeldActor> HeldActorClass;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult Target;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Angle;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Charge;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Velocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsCharged;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDNonVRMeleeAttackType AttackType;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector SplayDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<FTWDNonVRMeleeAttackHitDetails> Hits;
    
    TWD_API FTWDNonVRMeleeAttackDetails();
};

