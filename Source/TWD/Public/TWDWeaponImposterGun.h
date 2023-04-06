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
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<ASDIWeaponFirearm> FirearmToSpawnOnDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<ASDIHeldActor> BrokenFirearmToSpawnOnDrop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float BrokenFirearmSpawnChance;
    
    UPROPERTY(Transient)
    bool bReturningToInventory;
    
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EWeaponAnimation WeaponAnimType;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bIsRevolver;
    
    UPROPERTY(EditAnywhere)
    float HitAccuracyMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced)
    USkeletalMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UAkComponent* AkAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* FiredRoundAudioEvent;
    
    ATWDWeaponImposterGun(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintPure)
    bool PredictFireModeTransform(ESDIInteractiveInteractType Type, FTransform& OutTransform) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsThreat(ATWDCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    bool IsHighThreat(ATWDCharacter* Character);
    
};

