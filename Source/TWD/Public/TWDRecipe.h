#pragma once
#include "CoreMinimal.h"
#include "SDIExportObject.h"
#include "UObject/NoExportTypes.h"
#include "TWDRecipeInfo.h"
#include "TWDRecipe.generated.h"

class UMaterialInstance;
class UTexture2D;

UCLASS(BlueprintType)
class TWD_API UTWDRecipe : public USDIExportObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FText RecipeName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName OnlineEntitlementName;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UTexture2D* RecipeUIImage;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FText RecipeUIDescription;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UMaterialInstance* RecipeBuildMaterial;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FTWDRecipeInfo> InputInfo;
    
    UPROPERTY(BlueprintReadWrite)
    TArray<FTWDRecipeInfo> OutputInfo;
    
    UPROPERTY(BlueprintReadWrite)
    FTWDRecipeInfo PrerequisiteItemInfo;
    
    UTWDRecipe();
    UFUNCTION(BlueprintCallable)
    static TMap<FGuid, int32> GetOutputsAsMap(const FGuid& RecipeGuid);
    
    UFUNCTION(BlueprintCallable)
    static TMap<FGuid, int32> GetInputsAsMap(const FGuid& RecipeGuid);
    
};

