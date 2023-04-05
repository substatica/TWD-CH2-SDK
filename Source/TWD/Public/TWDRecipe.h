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
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FText RecipeName;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FName OnlineEntitlementName;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UTexture2D* RecipeUIImage;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FText RecipeUIDescription;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UMaterialInstance* RecipeBuildMaterial;
    
    UPROPERTY(BlueprintReadOnly)
    TArray<FTWDRecipeInfo> InputInfo;
    
    UPROPERTY(BlueprintReadOnly)
    TArray<FTWDRecipeInfo> OutputInfo;
    
    UPROPERTY(BlueprintReadOnly)
    FTWDRecipeInfo PrerequisiteItemInfo;
    
    UTWDRecipe();
    UFUNCTION(BlueprintCallable)
    static TMap<FGuid, int32> GetOutputsAsMap(const FGuid& RecipeGuid);
    
    UFUNCTION(BlueprintCallable)
    static TMap<FGuid, int32> GetInputsAsMap(const FGuid& RecipeGuid);
    
};

