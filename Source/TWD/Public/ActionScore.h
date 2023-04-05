#pragma once
#include "CoreMinimal.h"
#include "EEGOAIActionTypes.h"
#include "SDIEnumTypeHandle.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ActionScore.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FActionScore {
    GENERATED_BODY()
public:
    UPROPERTY()
    float WeightedScore;
    
    UPROPERTY()
    float RawScore;
    
    UPROPERTY()
    float Weight;
    
    UPROPERTY()
    EEGOAIActionTypes OutState;
    
    UPROPERTY()
    FSDIEnumTypeHandle OutStateEx;
    
    UPROPERTY()
    TWeakObjectPtr<AActor> Target;
    
    UPROPERTY()
    FVector PointOfInterest;
    
    UPROPERTY()
    bool CommitToMemory;
    
    UPROPERTY()
    int32 GOBReservationId;
    
    UPROPERTY()
    FVector GOBReservationLoc;
    
    UPROPERTY()
    FRotator GOBReservationRot;
    
    TWD_API FActionScore();
};

