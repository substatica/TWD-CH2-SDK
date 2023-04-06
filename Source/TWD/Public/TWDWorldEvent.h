#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ETWDWorldEventType.h"
#include "EMapTerritoryNodeType.h"
#include "TWDWorldEvent.generated.h"

UCLASS(BlueprintType)
class TWD_API UTWDWorldEvent : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EMapTerritoryNodeType MapAssociated;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ETWDWorldEventType EventType;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName PlayerStartTag;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bHasDuration;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 MaxDuration;
    
    UPROPERTY(BlueprintReadWrite)
    int32 CurrentDuration;
    
    UPROPERTY(BlueprintReadWrite)
    bool bPendingNotification;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAutoComplete;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    bool bEventComplete;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAdvancesStory;
    
protected:
    UPROPERTY(EditDefaultsOnly)
    TArray<FName> IdentifyingTags;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FName> ProhibitedTags;
    
public:
    UTWDWorldEvent();
    UFUNCTION(BlueprintPure)
    bool IsNightEvent() const;
    
    UFUNCTION(BlueprintPure)
    bool IsDayEvent() const;
    
    UFUNCTION(BlueprintPure)
    TArray<FName> GetProhibitedTags() const;
    
    UFUNCTION(BlueprintPure)
    TArray<FName> GetIdentifyingTags() const;
    
    UFUNCTION(BlueprintCallable)
    bool CheckIfPendingCompletion();
    
};

