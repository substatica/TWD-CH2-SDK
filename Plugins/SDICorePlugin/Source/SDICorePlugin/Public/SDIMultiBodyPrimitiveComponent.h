#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "SDIMultiBodyPrimitiveComponent.generated.h"

UCLASS(Abstract, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDICOREPLUGIN_API USDIMultiBodyPrimitiveComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    USDIMultiBodyPrimitiveComponent();
};

