#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SDIComponentHistory.h"
#include "SDIWeaponHitEntry.h"
#include "SDIWeaponHitHistoryComponent.generated.h"

class UPrimitiveComponent;
class AActor;

UCLASS(BlueprintType, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIWeaponHitHistoryComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIComponentHistory DamageHistory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIComponentHistory CollisionHistory;
    
public:
    USDIWeaponHitHistoryComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateHistory();
    
    UFUNCTION(BlueprintCallable)
    void ResetHistory();
    
    UFUNCTION(BlueprintCallable)
    void ResetDamageHistoryTimestamp(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void ResetDamageHistory();
    
    UFUNCTION(BlueprintCallable)
    void ResetCollisionHistoryTimestamp(UPrimitiveComponent* Component, FName BodyName);
    
    UFUNCTION(BlueprintCallable)
    void ResetCollisionHistory();
    
    UFUNCTION(BlueprintPure)
    bool HasDamagedActor(AActor* Actor, float OverrideHistoryDuration) const;
    
    UFUNCTION(BlueprintPure)
    bool HasDamaged(UPrimitiveComponent* Component, bool bUseActor, float OverrideHistoryDuration) const;
    
    UFUNCTION(BlueprintPure)
    bool HasCollidedWithActor(AActor* Actor, float OverrideHistoryDuration) const;
    
    UFUNCTION(BlueprintPure)
    bool HasCollidedWith(UPrimitiveComponent* Component, FName BodyName, bool bUseActor, float OverrideHistoryDuration) const;
    
    UFUNCTION(BlueprintCallable)
    void AddToDamageHistory(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void AddToCollisionHistory(const FSDIWeaponHitEntry& Entry, bool bUpdate);
    
    UFUNCTION(BlueprintCallable)
    void AddArrayToDamageHistory(const TArray<FSDIWeaponHitEntry>& NewHits);
    
    UFUNCTION(BlueprintCallable)
    void AddArrayToCollisionHistory(const TArray<FSDIWeaponHitEntry>& NewHits);
    
};

