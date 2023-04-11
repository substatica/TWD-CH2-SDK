#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIDamageableActorSkin.generated.h"

class USDISkinObject;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIDamageableActorSkin {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float HealthTransitionPct;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<USDISkinObject> Skin;
    
    FSDIDamageableActorSkin();
};

