#pragma once
#include "CoreMinimal.h"
#include "SDISkinSectionalVariant.h"
#include "TWDSkinSkeletalMeshSet.h"
#include "TWDCharacterSkin.generated.h"

class USkeletalMesh;

UCLASS(Config=Game)
class UTWDCharacterSkin : public USDISkinSectionalVariant {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FTWDSkinSkeletalMeshSet> PreAuthored;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float PreAuthoredDuplicateWeightMul;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FTWDSkinSkeletalMeshSet> hair;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FTWDSkinSkeletalMeshSet> head;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FTWDSkinSkeletalMeshSet> Torso;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FTWDSkinSkeletalMeshSet> Leg;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HairDuplicateWeightMul;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HeadDuplicateWeightMul;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float TorsoDuplicateWeightMul;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float LegDuplicateWeightMul;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FName, float> ScalarDuplicateWeightMul;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ScalarDuplicateTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FName, float> ColorDuplicateWeightMul;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ColorChannelDuplicateTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FName, float> TextureDuplicateWeightMul;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bRestrictHairDuplication;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bRestrictHeadDuplication;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bRestrictTorsoDuplication;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bRestrictLegDuplication;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FName> RestrictScalarParams;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FName> RestrictColorParams;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FName> RestrictTextureParams;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    USkeletalMesh* StandInMesh;
    
public:
    UTWDCharacterSkin();
    UFUNCTION(BlueprintPure)
    USkeletalMesh* GetStandInMesh() const;
    
};

