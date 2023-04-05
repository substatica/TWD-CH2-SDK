#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EEGOAIActionTypes.h"
#include "SDIEnumTypeHandle.h"
#include "EGOAIConsideration.h"
#include "EGOAIAction.generated.h"

USTRUCT(BlueprintType)
struct FEGOAIAction : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool Disable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    EEGOAIActionTypes OutState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIEnumTypeHandle OutStateEx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool NeedsTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxCutoff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinCutoff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool CommitToMemory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FEGOAIConsideration> ConsiderationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FEGOAIConsideration> ConsiderationListOR;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString ExecuteOnScoreBPFuncName;
    
    TWD_API FEGOAIAction();
};

