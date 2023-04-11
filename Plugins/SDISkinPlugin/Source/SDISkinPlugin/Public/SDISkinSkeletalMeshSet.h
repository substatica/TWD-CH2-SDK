#pragma once
#include "CoreMinimal.h"
#include "SDISkinStitchedSkeletalMesh.h"
#include "SDIRandomSkinParamSet.h"
#include "SDISkinStitchedStaticMesh.h"
#include "SDIRandomSkinColorParam.h"
#include "SDISkinAttachment.h"
#include "SDIRandomSkinTextureParam.h"
#include "SDIRandomSkinScalarParam.h"
#include "SDISkinSkeletalMeshSet.generated.h"

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDISkinSkeletalMeshSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISkinStitchedSkeletalMesh> StitchedSkeletalMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISkinStitchedStaticMesh> StitchedStaticMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISkinAttachment> Attachments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FSDIRandomSkinScalarParam> ScalarParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FSDIRandomSkinColorParam> ColorParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FSDIRandomSkinTextureParam> TextureParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FSDIRandomSkinParamSet> ParamSetMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Weight;
    
    FSDISkinSkeletalMeshSet();
};

