#pragma once
#include "CoreMinimal.h"
#include "SDIInventorySlot.h"
#include "TWDInteractiveHighlightInterface.h"
#include "ETWDPlayerCharacterTickInventory.h"
#include "TWDAmmoPouchItemInfo.h"
#include "TWDAmmoPouch.generated.h"

class UStaticMeshComponent;
class ATWDWeaponGun;
class UCapsuleComponent;
class UObject;
class ATWDWeaponBowV2;
class ATWDWeaponBow;
class AActor;
class USceneComponent;
class UMaterialInstanceDynamic;
class UTWDWidgetComponent;

UCLASS()
class TWD_API ATWDAmmoPouch : public ASDIInventorySlot, public ITWDInteractiveHighlightInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    ATWDWeaponGun* HeldGunLeft;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    ATWDWeaponGun* HeldGunRight;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    ATWDWeaponGun* ActiveGun;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    bool bOwnerHoldingAmmo;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    ATWDWeaponBowV2* HeldBowLeft;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    ATWDWeaponBowV2* HeldBowRight;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    ATWDWeaponBowV2* ActiveBow;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    AActor* HeldFuelRecepticleLeft;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    AActor* HeldFuelRecepticleRight;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    AActor* ActiveFuelRecepticle;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float RangedGrabOverrideRadius;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ETWDPlayerCharacterTickInventory InventorySlotTickGroup;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* PouchRoot;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UStaticMeshComponent* PouchMesh;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UStaticMeshComponent* SlotMesh;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UCapsuleComponent* SlotCollision;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UMaterialInstanceDynamic* AmmoIconMatInst;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UTWDWidgetComponent* AmmoInfoWidget;
    
    UPROPERTY(BlueprintReadWrite, Instanced, Transient)
    UStaticMeshComponent* AmmoIconMesh;
    
    UPROPERTY(Transient)
    FTWDAmmoPouchItemInfo CurrentItemInfo;
    
public:
    ATWDAmmoPouch();
    UFUNCTION(BlueprintPure)
    bool WasPouchRecentlyRendered(float Tolerance) const;
    
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateItemInfo(const FTWDAmmoPouchItemInfo& ItemInfo);
    
    UFUNCTION(BlueprintCallable)
    int32 GetArrowPropCurrencyCount(UObject* InventoryHolder, ATWDWeaponBow* Bow);
    
    UFUNCTION(BlueprintCallable)
    int32 GetAmmoPropCurrencyCount(UObject* InventoryHolder, ATWDWeaponGun* Gun);
    
    
    // Fix for true pure virtual functions not being implemented
};

