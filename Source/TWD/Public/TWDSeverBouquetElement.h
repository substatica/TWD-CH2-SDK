#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ESDIAxis.h"
#include "ESeverBouquetAttachActor.h"
#include "RInt.h"
#include "RVector.h"
#include "RFloat.h"
#include "TWDSeverBouquetElement.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct TWD_API FTWDSeverBouquetElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bUseBoneSpacePrimarySeverAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ESDIAxis BoneSpacePrimarySeverAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<AActor> ActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRInt SpawnCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRVector SpawnLocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat SpawnLocationMaxBoneAxisOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRVector SpawnAngleOffsets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAlignToSeverDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAnchored;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName AnchorBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bEnablePhysics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat SpawnImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bUseAttachActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ESeverBouquetAttachActor AttachActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName AttachBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bDeferUntilSplayComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bShowDebugInfo;
    
    FTWDSeverBouquetElement();
};

