#pragma once
#include "CoreMinimal.h"
#include "AkComponent.h"
#include "TWDAutoTickAkComponent.generated.h"

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTWDAutoTickAkComponent : public UAkComponent {
    GENERATED_BODY()
public:
    UTWDAutoTickAkComponent();
};

