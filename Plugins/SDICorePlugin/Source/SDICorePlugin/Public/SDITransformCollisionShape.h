#pragma once
#include "CoreMinimal.h"
#include "SDICollisionShape.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SDITransformCollisionShape.generated.h"

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDITransformCollisionShape : public FSDICollisionShape {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector ShapeLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRotator ShapeRotation;
    
    FSDITransformCollisionShape();
};

