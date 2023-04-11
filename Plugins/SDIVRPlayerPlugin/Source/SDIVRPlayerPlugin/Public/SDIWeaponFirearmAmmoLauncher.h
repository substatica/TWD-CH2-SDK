#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "SDIWeaponFirearmAmmo.h"
#include "UObject/NoExportTypes.h"
#include "RFloatExp.h"
#include "SDIWeaponFirearmFiredPelletInfo.h"
#include "SDIWeaponFirearmAmmoLauncher.generated.h"

class ASDIHeldActor;
class AActor;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIWeaponFirearmAmmoLauncher : public ASDIWeaponFirearmAmmo {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ASDIHeldActor> LaunchedClass;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRFloatExp LaunchSpeed;
    
public:
    ASDIWeaponFirearmAmmoLauncher(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintNativeEvent)
    ASDIHeldActor* SpawnLaunchedActor(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, TSubclassOf<ASDIHeldActor> SpawnLaunchedClass, AActor* LaunchedOwner);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSpawnLaunchedActor(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, TSubclassOf<ASDIHeldActor> SpawnLaunchedClass, AActor* LaunchedOwner);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector GetLaunchVelocity(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, const FTransform& SpreadShotTransform, ASDIHeldActor* LaunchedActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSubclassOf<ASDIHeldActor> GetLaunchedClass(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform);
    
};

