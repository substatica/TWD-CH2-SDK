#pragma once
#include "CoreMinimal.h"
#include "SDISkinSectionalVariantSkeletalMeshSet.h"
#include "TWDSkinSkeletalMeshSetArmor.h"
#include "TWDSkinSkeletalMeshSet.generated.h"

USTRUCT(BlueprintType)
struct FTWDSkinSkeletalMeshSet : public FSDISkinSectionalVariantSkeletalMeshSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 MinGoreLevelWaveMode;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDSkinSkeletalMeshSetArmor Armor;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTWDSkinSkeletalMeshSetArmor NonVRArmor;
    
    TWD_API FTWDSkinSkeletalMeshSet();
};

