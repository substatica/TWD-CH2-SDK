#pragma once
#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "SDICharacterCapsuleComponent.generated.h"

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDICharacterCapsuleComponent : public UCapsuleComponent {
    GENERATED_BODY()
public:
    USDICharacterCapsuleComponent();
};

