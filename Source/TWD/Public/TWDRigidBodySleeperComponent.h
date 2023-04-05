#pragma once
#include "CoreMinimal.h"
#include "SDIRigidBodySleeperComponent.h"
#include "TWDRigidBodySleeperComponent.generated.h"

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTWDRigidBodySleeperComponent : public USDIRigidBodySleeperComponent {
    GENERATED_BODY()
public:
    UTWDRigidBodySleeperComponent();
};

