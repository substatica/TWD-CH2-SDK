#pragma once
#include "CoreMinimal.h"
#include "SDISkinCompositeSkeletalMeshMaterialMapping.generated.h"

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDISkinCompositeSkeletalMeshMaterialMapping {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    TMap<int32, int32> Mapping;
    
    FSDISkinCompositeSkeletalMeshMaterialMapping();
};

