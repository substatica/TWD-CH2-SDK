#pragma once
#include "CoreMinimal.h"
#include "SDIBlendAnimation.h"
#include "SDIRopeReactionStruggleTugAnim.generated.h"

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIRopeReactionStruggleTugAnim : public FSDIBlendAnimation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float Increment;
    
    UPROPERTY(Transient)
    bool bFromTug;
    
    FSDIRopeReactionStruggleTugAnim();
};

