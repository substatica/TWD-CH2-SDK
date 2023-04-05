#pragma once
#include "CoreMinimal.h"
#include "TWDInteractiveActor.h"
#include "Engine/EngineTypes.h"
#include "TWDSeamlessTravelVehicle.generated.h"

class APawn;
class ATWDSeamlessTravelVehicle;
class UBoxComponent;
class UPrimitiveComponent;
class AActor;
class APlayerController;

UCLASS()
class ATWDSeamlessTravelVehicle : public ATWDInteractiveActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UBoxComponent* Collision;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bStart;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bIsTravelling;
    
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<APawn>> OverlappedPawns;
    
public:
    ATWDSeamlessTravelVehicle(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintNativeEvent)
    void SetTravelling(bool bTravelling);
    
protected:
    UFUNCTION()
    void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
public:
    UFUNCTION(BlueprintCallable)
    static ATWDSeamlessTravelVehicle* GetTravelStartVehicle(APlayerController* PC);
    
    UFUNCTION(BlueprintCallable)
    static ATWDSeamlessTravelVehicle* GetTravellingVehicle(APlayerController* PC);
    
    UFUNCTION(BlueprintCallable)
    static ATWDSeamlessTravelVehicle* GetTravelDestinationVehicle(ATWDSeamlessTravelVehicle* StartVehicle);
    
};

