#pragma once
#include "CoreMinimal.h"
#include "RInt.h"
#include "SDISkinSkeletalMeshSet.h"
#include "SDISkinSkeletalMeshRandomPiecesSet.generated.h"

USTRUCT(BlueprintType)
struct SDISKINPLUGIN_API FSDISkinSkeletalMeshRandomPiecesSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString SetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRInt NumToChoose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FSDISkinSkeletalMeshSet> Sets;
    
    FSDISkinSkeletalMeshRandomPiecesSet();
};

