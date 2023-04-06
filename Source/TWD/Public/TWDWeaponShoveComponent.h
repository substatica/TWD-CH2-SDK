#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "SDIPlayerHandMove.h"
#include "ETWDCharacterHitRegion.h"
#include "SDIDamageData.h"
#include "Engine/EngineTypes.h"
#include "TWDWeaponShoveComponent.generated.h"

class ATWDCharacter;
class AActor;

UCLASS(BlueprintType, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTWDWeaponShoveComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanShove;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bShoveRequireTwoHands;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bCanShoveWhenWinded;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIPlayerHandMove ShoveMove;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ShoveMinPenetration;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TArray<ETWDCharacterHitRegion> ShoveRegionFilter;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ShoveCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIDamageData ShoveDamageData;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ShoveStaminaCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ShoveDurabilityCost;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDurabilityCanBreakOnShove;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<ATWDCharacter>, float> ShoveTimestamps;
    
public:
    UTWDWeaponShoveComponent();
    UFUNCTION()
    void OnShoveActorHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& HitInfo);
    
};

