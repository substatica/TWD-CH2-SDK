#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIWeightedAnimationSetBase.h"
#include "SDIWeightedAnimation.h"
#include "SDIWeightedAnimationSet.generated.h"

UCLASS(BlueprintType)
class SDICOREPLUGIN_API USDIWeightedAnimationSet : public USDIWeightedAnimationSetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    TArray<FSDIWeightedAnimation> Anims;
    
public:
    USDIWeightedAnimationSet();
    UFUNCTION(BlueprintCallable)
    static bool GetAnimationFromSet(const TSubclassOf<USDIWeightedAnimationSetBase>& AnimSetClass, FSDIWeightedAnimation& OutAnim);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    bool GetAnimation(FSDIWeightedAnimation& OutAnim) const;
    
};

