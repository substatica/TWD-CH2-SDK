#pragma once
#include "CoreMinimal.h"
#include "SDISignificanceActor.h"
#include "SDISignificanceStasisActor.generated.h"

class UActorComponent;

UCLASS()
class SDICOREPLUGIN_API ASDISignificanceStasisActor : public ASDISignificanceActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxActiveBin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 MaxVisibleBin;
    
    UPROPERTY(Instanced, Transient)
    TSet<UActorComponent*> ComponentsPreviouslyDeactivated;
    
    UPROPERTY(Instanced, Transient)
    TSet<UActorComponent*> ComponentsPreviouslyStoppedTicking;
    
    UPROPERTY(Transient)
    bool ActorPreviouslyDeactivated;
    
public:
    ASDISignificanceStasisActor(const FObjectInitializer& ObjectInitializer);
};

