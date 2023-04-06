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
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FBlackboardKeySelector TargetKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float AcceptanceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStopOnOverlap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bUsePathfinding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bProjectDestinationToNavigation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bCanStrafe;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStopMovementOnAbort;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<UNavigationQueryFilter> NavigationQueryFilter;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<AAIController> Controller;
    
    UTWDBTT_SimpleWalkerMoveTo();
    UFUNCTION()
    void OnMoveCompleted(FAIRequestID RequestID, TEnumAsByte<EPathFollowingResult::Type> Result);
    
};

