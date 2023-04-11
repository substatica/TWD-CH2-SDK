#pragma once
#include "CoreMinimal.h"
#include "SDISkinBasic.h"
#include "SDISkinSkeletalMesh.h"
#include "SDISkeletalMeshSkin.generated.h"

UCLASS()
class SDISKINPLUGIN_API USDISkeletalMeshSkin : public USDISkinBasic {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDISkinSkeletalMesh BaseSkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bIgnoreBaseSkeletalMeshForMerging;
    
    USDISkeletalMeshSkin();
};

