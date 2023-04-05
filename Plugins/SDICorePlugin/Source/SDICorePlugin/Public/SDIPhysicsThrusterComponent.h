#pragma once
#include "CoreMinimal.h"
#include "SDIThrusterEntry.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "SDIPhysicsThrusterComponent.generated.h"

class UCurveBase;
class USDIPhysicsThrusterComponent;
class UPrimitiveComponent;
class AActor;

UCLASS(BlueprintType, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDICOREPLUGIN_API USDIPhysicsThrusterComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    bool bDynamicallyCreated;
    
    UPROPERTY(Transient)
    TMap<int32, FSDIThrusterEntry> Thrusters;
    
public:
    USDIPhysicsThrusterComponent();
    UFUNCTION(BlueprintCallable)
    static void RemoveThrusterFrom(UPrimitiveComponent* Comp, int32 ID);
    
    UFUNCTION(BlueprintCallable)
    static USDIPhysicsThrusterComponent* GetThrusterComponentFor(AActor* Actor, bool bCreate);
    
    UFUNCTION(BlueprintCallable)
    static int32 AddThrusterTo(UPrimitiveComponent* Comp, FName BodyName, const FTransform& WorldTransform, bool bAttached, bool bAccelChange, float Force, float Duration, int32 LoopCount, bool bCreate);
    
    UFUNCTION(BlueprintCallable)
    static int32 AddAnimatedThrusterTo(UPrimitiveComponent* Comp, FName BodyName, const FTransform& WorldTransform, bool bAttached, bool bAccelChange, UCurveBase* ForceCurve, float ForceCurveScale, int32 LoopCount, bool bCreate);
    
};

