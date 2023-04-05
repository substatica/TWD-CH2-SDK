#pragma once
#include "CoreMinimal.h"
#include "ETWDTimeOfDay.h"
#include "MapTimeOfDayChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMapTimeOfDayChanged, ETWDTimeOfDay, TimeOfDay);

