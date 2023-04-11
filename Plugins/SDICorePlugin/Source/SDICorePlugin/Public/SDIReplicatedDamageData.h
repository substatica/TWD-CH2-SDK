#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/NetSerialization.h"
#include "Engine/EngineTypes.h"
#include "Engine/NetSerialization.h"
#include "SDIReplicatedDamageData.generated.h"

class UDamageType;
class AActor;
class APlayerState;
class APawn;
class UObject;

USTRUCT(BlueprintType)
struct SDICOREPLUGIN_API FSDIReplicatedDamageData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    TSubclassOf<UDamageType> DamageTypeClass;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    AActor* DamagedActor;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    APlayerState* DamagedPS;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    APawn* InstigatorPawn;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    APlayerState* InstigatorPS;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UObject* DamageCauser;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 DamageID;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult HitResult;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector_NetQuantizeNormal ShotDirection;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector_NetQuantize100 ImpactVelocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ImpactMass;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float HitReactImpulseMultiplier;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float HitReactMinSpeed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DamageIntended;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DamageTaken;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bRadialDamage;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    TArray<uint8> CustomData;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float Timestamp;
    
    FSDIReplicatedDamageData();
};

