#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIWeaponFirearm.h"
#include "UObject/NoExportTypes.h"
#include "EWeaponAnimation.h"
#include "ESDIInteractiveInteractType.h"
#include "TWDWeaponImposterGun.generated.h"

class UAkComponent;
class ASDIHeldActor;
class ATWDCharacter;
class USkeletalMeshComponent;
class UAkAudioEvent;

UCLASS()
class TWD_API ATWDWeaponImposterGun : public ASDIWeaponFirearm {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSubclassOf<ASDIWeaponFirearm> FirearmToSpawnOnDrop;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSubclassOf<ASDIHeldActor> BrokenFirearmToSpawnOnDrop;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float BrokenFirearmSpawnChance;
    
    UPROPERTY(Transient)
    bool bReturningToInventory;
    
public:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    EWeaponAnimation WeaponAnimType;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bIsRevolver;
    
    UPROPERTY(EditAnywhere)
    float HitAccuracyMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced)
    USkeletalMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UAkComponent* AkAudioComponent;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UAkAudioEvent* FiredRoundAudioEvent;
    
    ATWDWeaponImposterGun();
    UFUNCTION(BlueprintPure)
    bool PredictFireModeTransform(ESDIInteractiveInteractType Type, FTransform& OutTransform) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsThreat(ATWDCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    bool IsHighThreat(ATWDCharacter* Character);
    
};

