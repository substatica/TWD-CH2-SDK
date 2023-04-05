#pragma once
#include "CoreMinimal.h"
#include "DialogueFinishedDelegate.generated.h"

class UTWDDialogue;

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_TwoParams(FDialogueFinished, UTWDDialogue*, FinishedDialogue, bool, bCompleted);

