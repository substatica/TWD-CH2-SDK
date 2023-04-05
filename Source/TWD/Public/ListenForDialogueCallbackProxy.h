#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ListenForDialogueDelegateDelegate.h"
#include "Engine/DataTable.h"
#include "TWDDialogueOption.h"
#include "ListenForDialogueCallbackProxy.generated.h"

class UTWDDialogue;
class UListenForDialogueCallbackProxy;
class ATWDCharacter;

UCLASS(BlueprintType, MinimalAPI)
class UListenForDialogueCallbackProxy : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FListenForDialogueDelegate DialogueReceived;
    
    UPROPERTY(BlueprintAssignable)
    FListenForDialogueDelegate ListenExpired;
    
private:
    UPROPERTY(Transient)
    TArray<FDataTableRowHandle> OptionHandles;
    
public:
    UListenForDialogueCallbackProxy();
private:
    UFUNCTION()
    void OnListenExpired();
    
    UFUNCTION()
    void OnDialogueReceived(const FTWDDialogueOption& DialogueOption, ATWDCharacter* Instigator);
    
public:
    UFUNCTION(BlueprintCallable)
    static UListenForDialogueCallbackProxy* CreateProxyObjectForListenForDialogue(int32 NodeId, UTWDDialogue* Dialogue, ATWDCharacter* Character, TArray<FDataTableRowHandle> NewOptionHandles, float Duration);
    
};

