#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "TWDSignificanceVolume.generated.h"

class AActor;

UCLASS()
class ATWDSignificanceVolume : public AVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxSignificanceHumanTier2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxSignificanceAICharactersTier2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxSignificanceHumanTier1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxSignificanceAICharactersTier1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxSignificanceHumanTier0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxSignificanceAICharactersTier0;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxSignificanceHumanTier0HiSpec;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxSignificanceAICharactersTier0HiSpec;
    
    ATWDSignificanceVolume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION()
    void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);
    
    UFUNCTION()
    void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
    
};

