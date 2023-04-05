#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIDamageableActorSkin.generated.h"

class USDISkinObject;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIDamageableActorSkin {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float HealthTransitionPct;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSubclassOf<USDISkinObject> Skin;
    
    FSDIDamageableActorSkin();
};

