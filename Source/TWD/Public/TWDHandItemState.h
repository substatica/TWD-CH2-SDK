#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDNonVRMeleeAttackDetails.h"
#include "ETWDGunAction.h"
#include "TWDNonVREquipmentActionDetails.h"
#include "TWDHandItemState.generated.h"

class ASDIHeldActor;

USTRUCT(BlueprintType)
struct FTWDHandItemState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIHeldActor* PrevItem;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIHeldActor* Item;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TSubclassOf<ASDIHeldActor> PrevItemClass;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TSubclassOf<ASDIHeldActor> ItemClass;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bDestroyed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bConsume;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAimingThrow;
    
    UPROPERTY(Transient)
    bool bDesiredAttack;
    
    UPROPERTY(Transient)
    FTWDNonVRMeleeAttackDetails DesiredAttackDetails;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAttack;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTWDNonVRMeleeAttackDetails AttackDetails;
    
    UPROPERTY(Transient)
    ETWDGunAction DesiredGunAction;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDGunAction GunAction;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 GunReloadRounds;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 GunChamberedRounds;
    
    UPROPERTY(Transient)
    bool bDesiredEquipmentAction;
    
    UPROPERTY(Transient)
    FTWDNonVREquipmentActionDetails DesiredEquipmentActionDetails;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bEquipmentAction;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTWDNonVREquipmentActionDetails EquipmentActionDetails;
    
    TWD_API FTWDHandItemState();
};

