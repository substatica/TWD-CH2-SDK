#pragma once
#include "CoreMinimal.h"
#include "SDISkeletalMeshSkin.h"
#include "SDISkinSkeletalMeshRandomPiecesSet.h"
#include "SDISkeletalMeshSkinRandomPieces.generated.h"

UCLASS()
class SDISKINPLUGIN_API USDISkeletalMeshSkinRandomPieces : public USDISkeletalMeshSkin {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISkinSkeletalMeshRandomPiecesSet> Randomizers;
    
    USDISkeletalMeshSkinRandomPieces();
};

