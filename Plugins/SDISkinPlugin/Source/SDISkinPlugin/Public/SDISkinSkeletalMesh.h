#pragma once
#include "CoreMinimal.h"
#include "SDISkinMaterial.h"
#include "SDICollisionSettingOverrides.h"
#include "SDIRenderSettingOverrides.h"
#include "SDISkinSkeletalMesh.generated.h"

class USkeletalMesh;
class UObject;

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDISkinSkeletalMesh : public FSDISkinMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSoftObjectPtr<USkeletalMesh> Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSoftObjectPtr<UObject> Animation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDICollisionSettingOverrides CollisionOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIRenderSettingOverrides RenderOverrides;
    
    FSDISkinSkeletalMesh();
};

