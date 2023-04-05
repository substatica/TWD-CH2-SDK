#pragma once
#include "CoreMinimal.h"
#include "SDIInputButtonLongHoldSignatureDelegate.generated.h"

class UObject;

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_TwoParams(FSDIInputButtonLongHoldSignature, UObject*, Owner, bool, bDoubleTap);

