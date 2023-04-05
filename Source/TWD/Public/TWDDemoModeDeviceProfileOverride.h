#pragma once
#include "CoreMinimal.h"
#include "EDemoModeType.h"
#include "TWDDemoModeDeviceProfileOverride.generated.h"

USTRUCT(BlueprintType)
struct FTWDDemoModeDeviceProfileOverride {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    EDemoModeType DemoModeType;
    
    UPROPERTY(EditAnywhere)
    FString DeviceProfile;
    
    TWD_API FTWDDemoModeDeviceProfileOverride();
};

