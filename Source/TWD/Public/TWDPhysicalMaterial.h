#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIPhysicalMaterial.h"
#include "TWDPhysicalMaterial.generated.h"

class UParticleSystem;
class UObject;
class AActor;
class UHapticFeedbackEffect_Base;

UCLASS(CollapseCategories)
class UTWDPhysicalMaterial : public USDIPhysicalMaterial {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UParticleSystem* DefaultBulletParticle;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UObject* DefaultBulletSound;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSubclassOf<AActor> DefaultBulletDecal;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bBulletOrientUsingImpactVelocity;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UObject* DefaultFootstepSound;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UObject* DefaultGripSound;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float CharacterNoiseMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float ObjectNoiseMultiplier;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UParticleSystem* DefaultParticle;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSubclassOf<AActor> DefaultDecal;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UHapticFeedbackEffect_Base* DefaultHaptic;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UObject* SoundPlayEvent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UObject* SoundStopEvent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UObject* DamageSound;
    
public:
    UTWDPhysicalMaterial();
    UFUNCTION(BlueprintPure)
    UObject* GetSoundStopEvent() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetSoundPlayEvent() const;
    
    UFUNCTION(BlueprintPure)
    UParticleSystem* GetParticle() const;
    
    UFUNCTION(BlueprintPure)
    float GetObjectNoiseMultiplier() const;
    
    UFUNCTION(BlueprintPure)
    UHapticFeedbackEffect_Base* GetHaptic() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetDefaultGripSound() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetDefaultFootstepSound() const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<AActor> GetDecal() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetDamageSound() const;
    
    UFUNCTION(BlueprintPure)
    float GetCharacterNoiseMultiplier() const;
    
    UFUNCTION(BlueprintPure)
    UObject* GetBulletSound(UClass* BulletClass) const;
    
    UFUNCTION(BlueprintPure)
    UParticleSystem* GetBulletParticle(bool& bOrientUsingImpactVelocity, UClass* BulletClass) const;
    
    UFUNCTION(BlueprintPure)
    TSubclassOf<AActor> GetBulletDecal(UClass* BulletClass) const;
    
};

