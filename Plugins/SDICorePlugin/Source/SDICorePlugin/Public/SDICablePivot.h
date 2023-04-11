#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "Engine/NetSerialization.h"
#include "Engine/NetSerialization.h"
#include "SDICablePivot.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICablePivot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    EControllerHand hand;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FName PivotBody;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FName Body;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector_NetQuantize PivotPos;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector_NetQuantize100 BodyPos;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector_NetQuantize100 RelBodyPos;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector_NetQuantize100 BodyParentPos;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector_NetQuantize100 RelBodyParentPos;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Length;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ElasticLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float NonElasticLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float BodyParentLength;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Time;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float TautTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bIsTaut;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAllowElasticTautPhysics;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bCanBeUsedForMovement;
    
    FSDICablePivot();
};

