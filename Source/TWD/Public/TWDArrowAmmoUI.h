#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "TWDArrowAmmoUI.generated.h"

class UStaticMesh;
class UTWDUserWidget;
class UMaterialInterface;
class UStaticMeshComponent;
class UTWDWidgetComponent;

USTRUCT(BlueprintType)
struct FTWDArrowAmmoUI {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UStaticMesh* ArrowMesh;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UMaterialInterface* ArrowMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTransform MeshTransform;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<UTWDUserWidget> AmmoWidget;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTransform AmmoWidgetTransform;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UStaticMeshComponent* MeshComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UTWDWidgetComponent* WidgetComponent;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 CachedArrowCount;
    
    TWD_API FTWDArrowAmmoUI();
};

