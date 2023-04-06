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
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ATWDWeaponGun* HeldGunLeft;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ATWDWeaponGun* HeldGunRight;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ATWDWeaponGun* ActiveGun;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    bool bOwnerHoldingAmmo;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ATWDWeaponBowV2* HeldBowLeft;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ATWDWeaponBowV2* HeldBowRight;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ATWDWeaponBowV2* ActiveBow;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    AActor* HeldFuelRecepticleLeft;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    AActor* HeldFuelRecepticleRight;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    AActor* ActiveFuelRecepticle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RangedGrabOverrideRadius;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ETWDPlayerCharacterTickInventory InventorySlotTickGroup;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* PouchRoot;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UStaticMeshComponent* PouchMesh;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UStaticMeshComponent* SlotMesh;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
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
    ATWDAmmoPouch(const FObjectInitializer& ObjectInitializer);
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

