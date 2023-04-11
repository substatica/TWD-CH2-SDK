#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDISkinAttachment.h"
#include "SDISkinStitchedSkeletalMesh.h"
#include "SDIMeshMaterialParamMultiMap.h"
#include "SDISkinStitchedStaticMesh.h"
#include "Engine/EngineTypes.h"
#include "SDISkinDynamicData.generated.h"

class USDISkinObject;
class UObject;
class USkeletalMeshComponent;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDISkinDynamicData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<USDISkinObject> DefaultSkin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAsyncLoadSkin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bMergeSkeletalMeshes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bForcePhysicsStateRecreation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 AsyncLoadPriority;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TMap<UObject*, FSDISkinAttachment> Attachments;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TMap<USkeletalMeshComponent*, FSDISkinStitchedSkeletalMesh> StitchedSkeletalMeshes;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TMap<UStaticMeshComponent*, FSDISkinStitchedStaticMesh> StitchedStaticMeshes;
    
    UPROPERTY(Transient)
    FSDIMeshMaterialParamMultiMap SkinParams;
    
    UPROPERTY(Transient)
    FTimerHandle QueueSkinParamApplyTimerHandle;
    
    UPROPERTY(Transient)
    bool bInitializingSkinReplicationData;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bUsingFallbackMesh;
    
    FSDISkinDynamicData();
};

