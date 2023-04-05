#pragma once
#include "CoreMinimal.h"
#include "TWDDialogueOption.h"
#include "DialogueResponseReceivedDelegate.generated.h"

class ATWDCharacter;

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_TwoParams(FDialogueResponseReceived, const FTWDDialogueOption&, DialogueOption, ATWDCharacter*, Responder);

