#pragma once
#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "SDITelemetrySubsystem.generated.h"

UCLASS(BlueprintType)
class SDITELEMETRYPLUGIN_API USDITelemetrySubsystem : public UEngineSubsystem {
    GENERATED_BODY()
public:
    USDITelemetrySubsystem();
    UFUNCTION(BlueprintCallable)
    void SendEvent(const FString& Type, const TMap<FString, FString>& EventData);
    
};

