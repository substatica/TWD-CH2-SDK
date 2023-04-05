#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "ActionScore.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "EGOAIBTService.generated.h"

UCLASS()
class UEGOAIBTService : public UBTService {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    TArray<FActionScore> ActionScoreList;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBTargetKey;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBPOIKey;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBRawScoreKey;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBWeightedScoreKey;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBRequestStateKey;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBPreviousStateKey;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBRequestStateExKey;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBPreviousStateExKey;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBGOBReservationIdKey;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBGOBReservationLocKey;
    
    UPROPERTY(EditAnywhere)
    FBlackboardKeySelector BBGOBReservationRotKey;
    
public:
    UEGOAIBTService();
};

