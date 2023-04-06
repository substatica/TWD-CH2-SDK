#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ETWDCharacterHitRegion.h"
#include "UObject/NoExportTypes.h"
#include "TWDNonVRMeleeAttackHitDetails.generated.h"

USTRUCT(BlueprintType)
struct FTWDNonVRMeleeAttackHitDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult Hit;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWeakpoint;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bWeakpointIsDiseased;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bArmored;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bArmorBroken;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bStab;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bDismember;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDCharacterHitRegion HitRegion;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Direction;
    
    TWD_API FTWDNonVRMeleeAttackHitDetails();
};

