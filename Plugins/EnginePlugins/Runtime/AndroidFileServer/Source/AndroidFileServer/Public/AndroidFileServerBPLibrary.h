#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EAFSActiveType.h"
#include "AndroidFileServerBPLibrary.generated.h"

UCLASS(BlueprintType)
class UAndroidFileServerBPLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAndroidFileServerBPLibrary();
    UFUNCTION(BlueprintCallable)
    static bool StopFileServer(bool bUSB, bool bNetwork);
    
    UFUNCTION(BlueprintCallable)
    static bool StartFileServer(bool bUSB, bool bNetwork, int32 Port);
    
    UFUNCTION(BlueprintCallable)
    static TEnumAsByte<EAFSActiveType::Type> IsFileServerRunning();
    
};

