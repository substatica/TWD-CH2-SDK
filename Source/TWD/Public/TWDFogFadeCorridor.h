#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "TWDFogFadeCorridor.generated.h"

class AExponentialHeightFog;
class UBoxComponent;
class UPrimitiveComponent;

UCLASS()
class TWD_API ATWDFogFadeCorridor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Instanced)
    UBoxComponent* Collision;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    AExponentialHeightFog* TargetFog;
    
    UPROPERTY(Transient, VisibleAnywhere)
    AExponentialHeightFog* ActiveTargetFog;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    bool bForceEntryValue;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    float ValueOnEnter;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    float ValueOnExit;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    float CurrentValue;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    float TargetValue;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    float ValueChangeRate;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    FVector EnterLocation;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    FVector ExitLocation;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    float LastProgress;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    float EntryValue;
    
public:
    ATWDFogFadeCorridor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION()
    void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION()
    void Initialize();
    
};

