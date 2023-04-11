#pragma once
#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "SDICoreUtilityAITargetEntry.h"
#include "RFloat.h"
#include "SDICoreUtilityAITargetList.generated.h"

class USDICoreUtilityAI;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICoreUtilityAITargetList {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    int32 LOSChecksPerFrame;
    
    UPROPERTY(EditAnywhere)
    bool bForceTeamAttitudeUpdates;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    USDICoreUtilityAI* Owner;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 LOSCheckIndex;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FGenericTeamId OwnerTeam;
    
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<FSDICoreUtilityAITargetEntry> Targets;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRFloat Distance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRFloat Distance2D;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRFloat ViewAngleDeg;
    
    FSDICoreUtilityAITargetList();
};

