#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MapAttributeDataAsset.generated.h"

class UMaterialInterface;

UCLASS(BlueprintType)
class TWD_API UMapAttributeDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FText AttributeName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UMaterialInterface* Icon;
    
    UMapAttributeDataAsset();
};

