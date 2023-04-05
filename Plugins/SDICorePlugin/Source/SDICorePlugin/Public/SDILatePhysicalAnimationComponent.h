#pragma once
#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicalAnimationComponent.h"
#include "SDILatePhysicalAnimationComponent.generated.h"

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDICOREPLUGIN_API USDILatePhysicalAnimationComponent : public UPhysicalAnimationComponent {
    GENERATED_BODY()
public:
    USDILatePhysicalAnimationComponent();
};

