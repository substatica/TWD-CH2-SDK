#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SDIStreamingDoor.generated.h"

UCLASS()
class SDIWORLDGRAPHPLUGIN_API ASDIStreamingDoor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FName> LoadLevelNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FName> UnloadLevelNames;
    
    ASDIStreamingDoor(const FObjectInitializer& ObjectInitializer);
};

