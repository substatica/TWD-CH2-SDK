#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=PhysicsCore -ObjectName=ECollisionShape -FallbackName=ECollisionShape
#include "UObject/NoExportTypes.h"
#include "SDICollisionShape.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDICollisionShape {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    ECollisionShape ShapeType;
    
    UPROPERTY(EditAnywhere)
    FVector ShapeExtent;
    
public:
    FSDICollisionShape();
};

