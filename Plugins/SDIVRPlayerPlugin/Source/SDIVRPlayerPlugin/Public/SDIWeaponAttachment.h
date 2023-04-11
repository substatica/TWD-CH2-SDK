#pragma once
#include "CoreMinimal.h"
#include "SDITuningInventoryActor.h"
#include "ESDIWeaponAttachmentType.h"
#include "UObject/NoExportTypes.h"
#include "SDIWeaponAttachment.generated.h"

class ASDIWeaponActor;

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDIWeaponAttachment : public ASDITuningInventoryActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIWeaponAttachmentType AttachmentType;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName AttachComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName AttachSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FTransform AttachRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowRemoval;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float AttachDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bTryAttachOnTick;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bTryAttachOnDropped;
    
    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_RepWeaponOwner)
    ASDIWeaponActor* RepWeaponOwner;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIWeaponActor* LocalWeaponOwner;
    
    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_bRepAttached)
    bool bRepAttached;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bLocalAttached;
    
public:
    ASDIWeaponAttachment(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    void WeaponOwnerUpdated();
    
public:
    UFUNCTION(BlueprintCallable)
    bool TryAttachToWeapon();
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    void SetWeaponOwner(ASDIWeaponActor* NewOwner);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetWeaponOwner(ASDIWeaponActor* NewOwner);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerDetachFromWeapon();
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerAttachToWeapon();
    
    UFUNCTION()
    void OnRep_RepWeaponOwner(ASDIWeaponActor* OldRepWeaponOwner);
    
    UFUNCTION()
    void OnRep_bRepAttached(bool OldbRepAttached);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsAttached() const;
    
    UFUNCTION(BlueprintPure)
    ASDIWeaponActor* GetWeaponOwner() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DetachFromWeapon(bool bForce, bool bRemove, bool bReplicate);
    
    UFUNCTION(BlueprintPure)
    bool CanAttachToWeapon(ASDIWeaponActor* WeaponActor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool AttachToWeapon(bool bForce, bool bReplicate);
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    bool AllowRemoval() const;
    
};

