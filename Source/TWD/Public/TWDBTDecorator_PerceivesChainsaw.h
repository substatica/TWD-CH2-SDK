#pragma once
#include "CoreMinimal.h"
#include "TWDBTD_Base.h"
#include "TWDBTDecorator_PerceivesChainsaw.generated.h"

UCLASS()
class UTWDBTDecorator_PerceivesChainsaw : public UTWDBTD_Base {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float MaxDistanceToChainsaw;
    
    UTWDBTDecorator_PerceivesChainsaw();
};

