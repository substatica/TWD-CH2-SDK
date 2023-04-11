#pragma once
#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "ESDIInteractRangeType.h"
#include "UObject/NoExportTypes.h"
#include "SDIPlayerHandInteractComponentEntry.generated.h"

class ASDIPlayerController;
class UPrimitiveComponent;
class AActor;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIPlayerHandInteractComponentEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<ASDIPlayerController> WeakController;
    
    UPROPERTY(BlueprintReadWrite, Export, Transient)
    TWeakObjectPtr<UPrimitiveComponent> Component;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<AActor> Actor;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Location;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector SegmentLocation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector RootLocation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LateralDistance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ScreenAngleDeg;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float SortScore;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ESDIInteractRangeType RangeType;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    EControllerHand ControllerHand;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bInsideCapsule;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bEmbedded;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bOnscreen;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bHighlighted;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Timestamp;
    
private:
    UPROPERTY(Transient)
    bool bTestedLOS;
    
    UPROPERTY(Transient)
    bool bUsedShortcutLOS;
    
    UPROPERTY(Transient)
    bool bValidLOS;
    
    UPROPERTY(Transient)
    bool bHasLOS;
    
    UPROPERTY(Transient)
    FVector HandLOSLocation;
    
    UPROPERTY(Transient)
    FVector CompLOSLocation;
    
    UPROPERTY(Transient)
    bool bTestedValidInteractionHighlight;
    
    UPROPERTY(Transient)
    bool bValidInteractionHighlight;
    
public:
    FSDIPlayerHandInteractComponentEntry();
};

