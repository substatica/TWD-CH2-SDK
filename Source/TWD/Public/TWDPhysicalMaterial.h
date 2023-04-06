#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIPhysicalMaterial.h"
#include "TWDPhysicalMaterial.generated.h"

class UParticleSystem;
class UObject;
class AActor;
class UObject;

UCLASS(CollapseCategories)
class UTWDPhysicalMaterial : public USDIPhysicalMaterial {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UParticleSystem* DefaultBulletParticle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UObject* DefaultBulletSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<AActor> DefaultBulletDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bBulletOrientUsingImpactVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UObject* DefaultFootstepSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UObject* DefaultGripSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float CharacterNoiseMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ObjectNoiseMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UParticleSystem* DefaultParticle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<AActor> DefaultDecal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UObject* DefaultHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UObject* SoundPlayEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UObject* SoundStopEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
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
    UObject* GetHaptic() const;
    
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

