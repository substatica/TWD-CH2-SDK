#include "PlayDialogueLineCallbackProxy.h"

class ATWDCharacter;
class UTWDDialogue;
class UPlayDialogueLineCallbackProxy;

void UPlayDialogueLineCallbackProxy::OnDialogueLineSkipped() {
}

void UPlayDialogueLineCallbackProxy::OnDialogueLineFinished(const FDialogueLine& DialogueLine, bool bCompleted) {
}

UPlayDialogueLineCallbackProxy* UPlayDialogueLineCallbackProxy::CreateProxyObjectForPlayDialogueLine(UTWDDialogue* Dialogue, ATWDCharacter* Character, FDataTableRowHandle NewDialogueLineHandle, EDialogueOverlapHandlingMethod OverlapHandlingMethod) {
    return NULL;
}

UPlayDialogueLineCallbackProxy::UPlayDialogueLineCallbackProxy() {
}

