#pragma once
#include "CoreMinimal.h"
#include "TWDGameMode.h"
#include "TWDWaveModeGameMode.generated.h"

class USDIWeaponFirearmFireModeComponent;
class ASDIWeaponFirearm;
class AController;
class UTWDCraftingTableProgression;
class APawn;
class ASDIWeaponFirearmAmmo;

UCLASS(NonTransient)
class TWD_API ATWDWaveModeGameMode : public ATWDGameMode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 BalancedWaveCount;
    
    UPROPERTY(EditAnywhere, Instanced)
    TArray<UTWDCraftingTableProgression*> CraftingTableProgressions;
    
    ATWDWaveModeGameMode();
    UFUNCTION(BlueprintCallable)
    void SetAllWavesCompleted(bool bSet);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnFiringWeapon(AController* Controller, APawn* Pawn, ASDIWeaponFirearm* Firearm, USDIWeaponFirearmFireModeComponent* Firemode, ASDIWeaponFirearmAmmo* Ammo, int32 ShotID);
    
    UFUNCTION(BlueprintPure)
    bool AllWavesCompleted() const;
    
};

