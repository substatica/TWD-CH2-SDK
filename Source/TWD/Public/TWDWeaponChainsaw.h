#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDWeaponActor.h"
#include "SDIDamageData.h"
#include "RFloat.h"
#include "SDIBlendOption.h"
#include "SDIAuxTickFunction.h"
#include "Engine/EngineTypes.h"
#include "TWDWeaponChainsaw.generated.h"

class USDIAsyncOverlapEventGeneratorComponent;
class UStaticMeshComponent;
class UShapeComponent;
class ASDIInventoryActor;
class UPrimitiveComponent;
class UObject;
class AActor;

UCLASS()
class TWD_API ATWDWeaponChainsaw : public ATWDWeaponActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Instanced)
    USDIAsyncOverlapEventGeneratorComponent* OverlapGenerator;
    
    UPROPERTY(EditDefaultsOnly)
    float EnvironmentalEffectsRefreshTime;
    
    UPROPERTY(EditDefaultsOnly)
    float EnvironmentalSoundRefreshTime;
    
    UPROPERTY(EditDefaultsOnly)
    float BladeLength;
    
    UPROPERTY(EditDefaultsOnly)
    float BladeRadius;
    
    UPROPERTY(EditDefaultsOnly)
    float ReflectionAngle;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIDamageData ChainsawEnvironmentalDamage;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIDamageData ChainsawCharacterDamagePerSecond;
    
    UPROPERTY(EditDefaultsOnly)
    FRFloat OverlapScaleSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    FSDIBlendOption OverlapScaleSpeedBlend;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bAllowWorldOverlap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float FuelAmount;
    
public:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TSubclassOf<ASDIInventoryActor> FuelCurrencyClass;
    
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bMotorIsOn;
    
    UPROPERTY(Transient)
    float MotorOnDefaultMassInKg;
    
    UPROPERTY(Transient)
    float MotorOnMassOverrideAlpha;
    
    UPROPERTY(EditAnywhere, Transient)
    UShapeComponent* ChainsawBladeCollisionComponent;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<TWeakObjectPtr<UPrimitiveComponent>> BladeOverlapComponents;
    
    UPROPERTY(Transient)
    float ChainsawFXTimer;
    
    UPROPERTY(Transient)
    float ChainsawSoundTimer;
    
    UPROPERTY(Transient)
    bool bSoundIsPlaying;
    
    UPROPERTY(Transient)
    UObject* SoundPlayEvent;
    
    UPROPERTY(Transient)
    UObject* SoundStopEvent;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UStaticMeshComponent* RefuelGuideMeshComponent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ChainsawThreatDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float ChainsawHighThreatDistance;
    
    UPROPERTY(Transient)
    FSDIAuxTickFunction PostPhysicsTick;
    
public:
    ATWDWeaponChainsaw(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintImplementableEvent)
    void TickPostPhysics(UObject* TickOwner, float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void ShowRefuelGuide();
    
    UFUNCTION()
    void OnChainsawBladeEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnChainsawBladeBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void HideRefuelGuide();
    
    UFUNCTION(BlueprintPure)
    float GetFuelPropCurrencyAmountInternal(UObject* InventoryHolder) const;
    
};

