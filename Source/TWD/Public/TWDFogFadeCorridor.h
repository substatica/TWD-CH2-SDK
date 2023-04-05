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
    UPROPERTY(BlueprintReadOnly, EditInstanceOnly, Instanced)
    UBoxComponent* Collision;
    
    UPROPERTY(BlueprintReadOnly, EditInstanceOnly)
    AExponentialHeightFog* TargetFog;
    
    UPROPERTY(Transient, VisibleAnywhere)
    AExponentialHeightFog* ActiveTargetFog;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    bool bForceEntryValue;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    float ValueOnEnter;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    float ValueOnExit;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    float CurrentValue;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    float TargetValue;
    
    UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
    float ValueChangeRate;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    FVector EnterLocation;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    FVector ExitLocation;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    float LastProgress;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    float EntryValue;
    
public:
    ATWDFogFadeCorridor();
    UFUNCTION()
    void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION()
    void Initialize();
    
};

