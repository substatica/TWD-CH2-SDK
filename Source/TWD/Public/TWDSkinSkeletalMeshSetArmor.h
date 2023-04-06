#pragma once
#include "CoreMinimal.h"
#include "TWDSkinSkeletalMeshSetArmor.generated.h"

class UParticleSystem;
class UDestructibleMesh;
class UAkAudioEvent;

USTRUCT(BlueprintType)
struct FTWDSkinSkeletalMeshSetArmor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 ArmorAmount;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSoftObjectPtr<UParticleSystem> BreakFXParticle;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float BreakFXDestructibleMeshLifespan;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSoftObjectPtr<UDestructibleMesh> BreakFXDestructibleMesh;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float BreakFXDestructibleMeshImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UAkAudioEvent* BreakFXSound;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FName BreakFXSocket;
    
    UPROPERTY(Transient)
    UParticleSystem* PreloadedBreakFXParticle;
    
    UPROPERTY(Transient)
    UDestructibleMesh* PreloadedBreakFXDestructibleMesh;
    
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    float DestroyedTimestamp;
    
    TWD_API FTWDSkinSkeletalMeshSetArmor();
};

