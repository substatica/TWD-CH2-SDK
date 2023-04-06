#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ETWDInteractionType.h"
#include "TWDInteractiveHighlightManagerEntry.generated.h"

class ATWDInteractiveHighlightActor;
class AActor;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FTWDInteractiveHighlightManagerEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UPrimitiveComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTransform RelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAnyInteractions;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bLeftHandClose;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bLeftHandRanged;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bRightHandClose;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bRightHandRanged;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bValidLOS;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bHasLOS;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bOutOfRange;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Highlight;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDInteractionType Type;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ATWDInteractiveHighlightActor* HighlightActor;
    
    TWD_API FTWDInteractiveHighlightManagerEntry();
};

