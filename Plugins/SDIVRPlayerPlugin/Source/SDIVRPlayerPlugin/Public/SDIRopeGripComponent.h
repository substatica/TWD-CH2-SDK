#pragma once
#include "CoreMinimal.h"
#include "SDIPointGripComponent.h"
#include "SDIRopeGripComponent.generated.h"

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIRopeGripComponent : public USDIPointGripComponent {
    GENERATED_BODY()
public:
    USDIRopeGripComponent();
};

