#pragma once
#include "CoreMinimal.h"
#include "OnAnimationActionPlayDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAnimationActionPlayDelegate, FName, NotifyName);

