#pragma once
#include "CoreMinimal.h"
#include "AI/Navigation/NavigationTypes.h"
#include "TWDPathQueryInfo.h"
#include "TWDNavPathQueryDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_TwoParams(FTWDNavPathQueryDelegate, TEnumAsByte<ENavigationQueryResult::Type>, ResultType, FTWDPathQueryInfo, NavPath);

