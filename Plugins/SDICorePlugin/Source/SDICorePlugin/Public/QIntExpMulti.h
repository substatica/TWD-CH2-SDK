#pragma once
#include "CoreMinimal.h"
#include "QIntExp.h"
#include "QIntExpMulti.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FQIntExpMulti : public FQIntExp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float NumSamples;
    
    FQIntExpMulti();
};

