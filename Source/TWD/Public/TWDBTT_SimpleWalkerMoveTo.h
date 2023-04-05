#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Navigation/PathFollowingComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "AITypes.h"
#include "TWDBTT_SimpleWalkerMoveTo.generated.h"

class UNavigationQueryFilter;
class AAIController;

UCLASS(BlueprintType)
class TWD_API UTWDBTT_SimpleWalkerMoveTo : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FBlackboardKeySelector TargetKey;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float AcceptanceRadius;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bStopOnOverlap;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bUsePathfinding;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bProjectDestinationToNavigation;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bCanStrafe;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bStopMovementOnAbort;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSubclassOf<UNavigationQueryFilter> NavigationQueryFilter;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<AAIController> Controller;
    
    UTWDBTT_SimpleWalkerMoveTo();
    UFUNCTION()
    void OnMoveCompleted(FAIRequestID RequestID, TEnumAsByte<EPathFollowingResult::Type> Result);
    
};

