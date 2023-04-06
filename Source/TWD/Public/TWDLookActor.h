#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TWDLookActor.generated.h"

class UMaterialInstanceDynamic;
class UStaticMeshComponent;
class UAkAudioEvent;
class UTWDAutoTickAkComponent;

UCLASS()
class TWD_API ATWDLookActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* StartLookingAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* LookingLoopPlayAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* LookingLoopStopAudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* FinishLookingAudioEvent;
    
protected:
    UPROPERTY(Instanced, VisibleAnywhere)
    UStaticMeshComponent* LookMeshComponent;
    
    UPROPERTY(Transient)
    UMaterialInstanceDynamic* LookMaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDAutoTickAkComponent* AkAudioComponent;
    
public:
    ATWDLookActor(const FObjectInitializer& ObjectInitializer);
};

