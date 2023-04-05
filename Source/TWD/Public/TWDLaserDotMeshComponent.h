#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TWDLaserDotMeshComponent.generated.h"

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TWD_API UTWDLaserDotMeshComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UTWDLaserDotMeshComponent();
};

