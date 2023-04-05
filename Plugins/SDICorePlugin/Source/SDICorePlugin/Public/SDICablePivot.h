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
    UPROPERTY(BlueprintReadOnly, Transient)
    EControllerHand hand;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FName PivotBody;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FName Body;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector_NetQuantize PivotPos;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector_NetQuantize100 BodyPos;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector_NetQuantize100 RelBodyPos;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector_NetQuantize100 BodyParentPos;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FVector_NetQuantize100 RelBodyParentPos;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Length;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float ElasticLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float NonElasticLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float BodyParentLength;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float Time;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float TautTime;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bIsTaut;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bAllowElasticTautPhysics;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bCanBeUsedForMovement;
    
    FSDICablePivot();
};

