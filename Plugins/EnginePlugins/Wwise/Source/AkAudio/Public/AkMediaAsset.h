#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkMediaAsset.generated.h"

class UAkMediaAssetData;

UCLASS(BlueprintType)
class AKAUDIO_API UAkMediaAsset : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(VisibleAnywhere)
    uint32 ID;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadOnly, VisibleAnywhere)
    FString MediaName;
    
    UPROPERTY(VisibleAnywhere)
    bool AutoLoad;
    
    UPROPERTY(EditAnywhere)
    TArray<UObject*> UserData;
    
    UPROPERTY(VisibleAnywhere)
    FString Language;
    
private:
    UPROPERTY(Transient)
    UAkMediaAssetData* CurrentMediaAssetData;
    
public:
    UAkMediaAsset();
};

