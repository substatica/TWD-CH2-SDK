#pragma once
#include "CoreMinimal.h"
#include "SDIRandomSkinScalarParam.h"
#include "SDISkinChildComponentSkeletalMesh.h"
#include "SDISkinObject.h"
#include "SDISkinStitchedSkeletalMesh.h"
#include "SDISkinStitchedStaticMesh.h"
#include "SDISkinChildComponentMaterial.h"
#include "SDISkinChildComponentStaticMesh.h"
#include "SDISkinAttachment.h"
#include "SDIRandomSkinColorParam.h"
#include "SDIRandomSkinTextureParam.h"
#include "SDIRandomSkinParamSet.h"
#include "SDISkinBasic.generated.h"

UCLASS()
class SDISKINPLUGIN_API USDISkinBasic : public USDISkinObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISkinStitchedSkeletalMesh> StitchedSkeletalMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISkinStitchedStaticMesh> StitchedStaticMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISkinChildComponentSkeletalMesh> ChildComponentSkeletalMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISkinChildComponentStaticMesh> ChildComponentStaticMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISkinChildComponentMaterial> ChildComponentMaterials;
    
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
    
    USDISkinBasic();
};

