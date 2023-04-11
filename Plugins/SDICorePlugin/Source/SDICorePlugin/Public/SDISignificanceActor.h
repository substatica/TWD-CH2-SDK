#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SDISignificanceBinInterface.h"
#include "UObject/NoExportTypes.h"
#include "SDISignificanceActor.generated.h"

class UObject;

UCLASS()
class SDICOREPLUGIN_API ASDISignificanceActor : public AActor, public ISDISignificanceBinInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName SignificanceTag;
    
public:
    ASDISignificanceActor(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION()
    float SignificanceFunction(UObject* QueryObj, const FTransform& ViewerTransform);
    
    
    // Fix for true pure virtual functions not being implemented
};

