#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TWDTelemetrySubsystem.generated.h"

UCLASS(BlueprintType)
class TWD_API UTWDTelemetrySubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UTWDTelemetrySubsystem();
    UFUNCTION(BlueprintCallable)
    void SendEvent(const FString& Type, TMap<FString, FString>& EventData);
    
    UFUNCTION(BlueprintCallable)
    void RemovePreCrashInfo(int32 Index);
    
    UFUNCTION()
    void AddPreCrashInfoTelemetryData(TMap<FString, FString>& TelemetryData);
    
    UFUNCTION(BlueprintCallable)
    int32 AddPreCrashInfo(FString& PreCrashString);
    
    UFUNCTION()
    void AddGlobalTelemetryData(TMap<FString, FString>& TelemetryData);
    
};

