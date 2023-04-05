#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkMediaAssetManager.generated.h"

class UAkMediaAsset;

UCLASS()
class AKAUDIO_API UAkMediaAssetManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(VisibleAnywhere)
    TMap<uint32, UAkMediaAsset*> StreamingMediaMap;
    
    UAkMediaAssetManager();
};

