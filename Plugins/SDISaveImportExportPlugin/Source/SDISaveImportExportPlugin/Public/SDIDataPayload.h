#pragma once
#include "CoreMinimal.h"
#include "SDIDataPayload.generated.h"

USTRUCT(BlueprintType)
struct SDISAVEIMPORTEXPORTPLUGIN_API FSDIDataPayload {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    FString AppVersion;
    
    UPROPERTY(BlueprintReadWrite)
    FString Platform;
    
    UPROPERTY(BlueprintReadWrite)
    FString DeviceModel;
    
    UPROPERTY(BlueprintReadWrite)
    FString ClassName;
    
    UPROPERTY(BlueprintReadWrite)
    FString SerializedData;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FString> AdditionalFields;
    
    FSDIDataPayload();
};

