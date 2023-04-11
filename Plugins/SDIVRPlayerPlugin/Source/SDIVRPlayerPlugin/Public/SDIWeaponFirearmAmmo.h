#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIWeaponFirearmFiredPelletInfo.h"
#include "SDIWeaponFirearmFiredShotInfo.h"
#include "SDIWeaponAttachment.h"
#include "UObject/NoExportTypes.h"
#include "SDISpreadSettings.h"
#include "SDIWeaponFirearmAmmo.generated.h"

class ASDIInventoryActor;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIWeaponFirearmAmmo : public ASDIWeaponAttachment {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ASDIInventoryActor> CurrencyClass;
    
    UPROPERTY(EditDefaultsOnly)
    bool bNonPlayerHasInfiniteCurrency;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 Cost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 NumPellets;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float SpreadDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISpreadSettings> PelletSpreadSettings;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISpreadSettings> PlayerPelletSpreadSettings;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<FSDISpreadSettings> NonVRPlayerPelletSpreadSettings;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIInventoryActor> CurrencyPtr;
    
public:
    ASDIWeaponFirearmAmmo(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintPure)
    bool HasInfiniteCurrency() const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<ASDIInventoryActor> GetCurrencyClass() const;
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    ASDIInventoryActor* GetCurrency() const;
    
    UFUNCTION(BlueprintNativeEvent)
    int32 GetCost() const;
    
    UFUNCTION(BlueprintNativeEvent)
    int32 Fire(const FSDIWeaponFirearmFiredShotInfo& FiredShotInfo, const FTransform& ShotTransform);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FTransform ApplySpread(const FSDIWeaponFirearmFiredPelletInfo& FiredPelletInfo, const FTransform& ShotTransform, float AdditionalSpread);
    
};

