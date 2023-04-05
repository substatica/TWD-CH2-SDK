#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDWeaponActor.h"
#include "InputCoreTypes.h"
#include "UObject/NoExportTypes.h"
#include "TWDSapGlove.generated.h"

class UStaticMeshComponent;
class ATWDCharacter;
class USkeletalMeshComponent;
class AActor;
class USplineComponent;
class UTWDWeaponHitCapsuleComponent;
class USDIPointGripComponent;
class UMaterialInterface;
class ATWDPlayerHand;
class UHapticFeedbackEffect_Base;
class UDamageType;

UCLASS()
class ATWDSapGlove : public ATWDWeaponActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Instanced, VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UStaticMeshComponent* EquipGuideMeshComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USkeletalMeshComponent* EquippedMeshComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USDIPointGripComponent* PrimaryGripLeftComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USDIPointGripComponent* PrimaryGripRightComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USDIPointGripComponent* EquippedGripComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UTWDWeaponHitCapsuleComponent* WeaponHitCapsule;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UTWDWeaponHitCapsuleComponent* AttachedHitCapsule;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UTWDWeaponHitCapsuleComponent* GrippedHitCapsule;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    USplineComponent* EquipSplineComponent;
    
    UPROPERTY(EditDefaultsOnly)
    EControllerHand TargetHand;
    
    UPROPERTY(EditDefaultsOnly)
    FTransform AttachTransform;
    
    UPROPERTY(EditDefaultsOnly)
    FTransform EquipGuideAttachTransform;
    
    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface* EquipGuideMaterial;
    
    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface* InvalidEquipMaterial;
    
    UPROPERTY(Transient)
    ATWDPlayerHand* EquippingHand;
    
    UPROPERTY(Transient)
    ATWDPlayerHand* EquippedHand;
    
    UPROPERTY(EditDefaultsOnly)
    float StartEquipRadius;
    
    UPROPERTY(EditDefaultsOnly)
    float EquipRadius;
    
    UPROPERTY(EditDefaultsOnly)
    float StartRemoveRadius;
    
    UPROPERTY(EditDefaultsOnly)
    float StartRemoveAngleMax;
    
    UPROPERTY(EditDefaultsOnly)
    float RemoveRadius;
    
    UPROPERTY(EditDefaultsOnly)
    float RemoveHandOffset;
    
    UPROPERTY(EditDefaultsOnly)
    UHapticFeedbackEffect_Base* EquippedHapticEffect;
    
    UPROPERTY(EditDefaultsOnly)
    float EquippedEffectScale;
    
    UPROPERTY(EditDefaultsOnly)
    UHapticFeedbackEffect_Base* RemovedHapticEffect;
    
    UPROPERTY(EditDefaultsOnly)
    float RemovedEffectScale;
    
    UPROPERTY(EditDefaultsOnly)
    UHapticFeedbackEffect_Base* EquippingHapticEffect;
    
    UPROPERTY(EditDefaultsOnly)
    float EquippingEffectScale;
    
public:
    ATWDSapGlove(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION()
    void OnCharacterDied(ATWDCharacter* Character, float PrevHealth, TSubclassOf<UDamageType> DamageTypeClass, AActor* DamageCauser);
    
};

