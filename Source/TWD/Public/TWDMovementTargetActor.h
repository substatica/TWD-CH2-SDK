#pragma once
#include "CoreMinimal.h"
#include "EPopoutLocation.h"
#include "EMovementTargetType.h"
#include "SDIMovementTargetActor.h"
#include "TWDInteractiveHighlightInterface.h"
#include "ECoverType.h"
#include "UObject/NoExportTypes.h"
#include "TWDMovementTargetActor.generated.h"

class AActor;
class UArrowComponent;

UCLASS()
class ATWDMovementTargetActor : public ASDIMovementTargetActor, public ITWDInteractiveHighlightInterface {
    GENERATED_BODY()
public:
    UPROPERTY(Instanced, Transient)
    UArrowComponent* LeftArrowPopout;
    
    UPROPERTY(Instanced, Transient)
    UArrowComponent* RightArrowPopout;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EMovementTargetType MoveTargetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ECoverType CoverType;
    
    UPROPERTY(EditDefaultsOnly)
    float CoverHeightCheck;
    
    UPROPERTY(EditDefaultsOnly)
    float CoverWidthCheck;
    
    UPROPERTY(EditDefaultsOnly)
    float CoverDistanceCheck;
    
    UPROPERTY(EditAnywhere)
    bool DisplayDebug;
    
private:
    UPROPERTY(Transient)
    AActor* OccupingAgent;
    
public:
    ATWDMovementTargetActor();
    UFUNCTION(BlueprintCallable)
    void SetOccupied(AActor* occupingActor);
    
    UFUNCTION(BlueprintCallable)
    bool IsValidCover();
    
    UFUNCTION(BlueprintCallable)
    bool GetPopoutPositionValid(FVector TargetPos, EPopoutLocation popoutSide, FVector& PopoutPosition);
    
    UFUNCTION(BlueprintCallable)
    bool GetOccupied(AActor*& occupingActor);
    
    UFUNCTION(BlueprintCallable)
    void ClearOccupied();
    
    
    // Fix for true pure virtual functions not being implemented
};

