#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EFactionReaction.h"
#include "EFaction.h"
#include "SDICorePlayerState.h"
#include "TWDHubStateInfo.h"
#include "TWDTopic.h"
#include "TWDPlayerStateInfo.h"
#include "TWDPlayerState.generated.h"

class UTWDTask;
class UTWDDialogue;

UCLASS()
class ATWDPlayerState : public ASDICorePlayerState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    TArray<UTWDTask*> Tasks;
    
    UPROPERTY(Transient)
    TArray<FTWDTopic> Topics;
    
    UPROPERTY(Transient)
    TMap<TSubclassOf<UTWDDialogue>, FString> DialogueBookmarks;
    
    UPROPERTY(Replicated, Transient)
    FTWDHubStateInfo RepHubState;
    
    UPROPERTY(Replicated, Transient)
    FTWDPlayerStateInfo RepPlayerState;
    
public:
    ATWDPlayerState(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetHubStateInfo(const FTWDHubStateInfo& NewHubState);
    
    UFUNCTION(BlueprintPure)
    FTWDHubStateInfo GetHubStateInfo() const;
    
    UFUNCTION(BlueprintCallable)
    float GetFactionReputation(EFaction Faction);
    
    UFUNCTION(BlueprintCallable)
    EFactionReaction GetFactionReaction(EFaction Faction);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AddFactionReputation(EFaction Faction, float Reputation);
    
};

