#pragma once
#include "CoreMinimal.h"
#include "SDISkinSkeletalMeshSet.h"
#include "SDISkinSectionalVariantSkeletalMeshSet.generated.h"

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDISkinSectionalVariantSkeletalMeshSet : public FSDISkinSkeletalMeshSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FName, FSDISkinSkeletalMeshSet> Variants;
    
    FSDISkinSectionalVariantSkeletalMeshSet();
};

