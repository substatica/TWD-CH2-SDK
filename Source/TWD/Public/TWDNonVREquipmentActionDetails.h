#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ETWDNonVREquipmentActionType.h"
#include "TWDNonVREquipmentActionDetails.generated.h"

class ASDIHeldActor;

USTRUCT(BlueprintType)
struct FTWDNonVREquipmentActionDetails {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIHeldActor* HeldActor;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TSubclassOf<ASDIHeldActor> HeldActorClass;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDNonVREquipmentActionType ActionType;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Time;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Duration;
    
    TWD_API FTWDNonVREquipmentActionDetails();
};

