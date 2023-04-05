#include "ListenForDialogueCallbackProxy.h"

class UListenForDialogueCallbackProxy;
class UTWDDialogue;
class ATWDCharacter;

void UListenForDialogueCallbackProxy::OnListenExpired() {
}

void UListenForDialogueCallbackProxy::OnDialogueReceived(const FTWDDialogueOption& DialogueOption, ATWDCharacter* Instigator) {
}

UListenForDialogueCallbackProxy* UListenForDialogueCallbackProxy::CreateProxyObjectForListenForDialogue(int32 NodeId, UTWDDialogue* Dialogue, ATWDCharacter* Character, TArray<FDataTableRowHandle> NewOptionHandles, float Duration) {
    return NULL;
}

UListenForDialogueCallbackProxy::UListenForDialogueCallbackProxy() {
}

