#pragma once
#include "CoreMinimal.h"
#include "SDIInputSplineActor.h"
#include "SDIPlayerHandMove.h"
#include "SDIThrowInputSplineActor.generated.h"

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIThrowInputSplineActor : public ASDIInputSplineActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bArcRequiresHold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bArcThrowOnRelease;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bArcAllowThrowBehind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bArcUseThrowMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIPlayerHandMove ArcThrowMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ArcThrowMoveYawAngleDeltaDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bMinArcVelocityUpdateArc;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MinArcVelocityResolution;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinArcVelocityMaxDistanceError;
    
public:
    ASDIThrowInputSplineActor();
protected:
    UFUNCTION(BlueprintNativeEvent)
    void UpdateThrowInputSpline(float DeltaSeconds);
    
};

