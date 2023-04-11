#pragma once
#include "CoreMinimal.h"
#include "SDICoreUtilityAITargetEntryLocation.h"
#include "GenericTeamAgentInterface.h"
#include "GenericTeamAgentInterface.h"
#include "SDICoreUtilityAITargetEntry.generated.h"

class USDICoreUtilityAI;
class AActor;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICoreUtilityAITargetEntry {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    USDICoreUtilityAI* Owner;
    
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    TWeakObjectPtr<AActor> Target;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Timer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDICoreUtilityAITargetEntryLocation Location;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDICoreUtilityAITargetEntryLocation LastKnownLocation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDICoreUtilityAITargetEntryLocation GroundLocation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FSDICoreUtilityAITargetEntryLocation LastKnownGroundLocation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FGenericTeamId TeamID;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TEnumAsByte<ETeamAttitude::Type> AttitudeTowards;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TEnumAsByte<ETeamAttitude::Type> AttitudeFrom;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bTeamAttitudeUpdated;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bForced;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bLocationBased;
    
    FSDICoreUtilityAITargetEntry();
};

