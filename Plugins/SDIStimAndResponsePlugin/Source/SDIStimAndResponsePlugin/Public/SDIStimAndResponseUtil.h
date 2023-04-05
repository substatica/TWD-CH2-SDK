#pragma once
#include "CoreMinimal.h"
#include "SDICollisionShape.h"
#include "SDIUtil.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "SDIStimAndResponseUtil.generated.h"

class UObject;
class USceneComponent;
class ASDIGameplayTagActor;
class AActor;
class UPrimitiveComponent;
class UDamageType;

UCLASS()
class SDISTIMANDRESPONSEPLUGIN_API USDIStimAndResponseUtil : public USDIUtil {
    GENERATED_BODY()
public:
    USDIStimAndResponseUtil();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void UpdateStimuli(UObject* Object);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void UpdateOverlapStimuli(UObject* Object);
    
    UFUNCTION(BlueprintPure)
    static bool SupportsGameplayTags(UObject* Object);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ASDIGameplayTagActor* SpawnStimuliShape(const UObject* WorldContextObject, const FGameplayTagContainer& Stimuli, const FTransform& Transform, const FSDICollisionShape& Shape, float LifeSpan, USceneComponent* AttachComp, FName AttachSocketName, FName CollisionProfileName);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ASDIGameplayTagActor* SpawnStimuli(const UObject* WorldContextObject, const FGameplayTagContainer& Stimuli, const FTransform& Transform, FVector Extent, float LifeSpan, USceneComponent* AttachComp, FName AttachSocketName, FName CollisionProfileName);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveGameplayTag(UObject* Object, FGameplayTag Tag, bool bUpdateStimuli);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool OverlapStimuliShape(const UObject* WorldContextObject, const FGameplayTagContainer& Stimuli, const FTransform& Transform, const FSDICollisionShape& Shape, FName CollisionProfileName);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool OverlapStimuli(const UObject* WorldContextObject, const FGameplayTagContainer& Stimuli, const FTransform& Transform, FVector Extent, FName CollisionProfileName);
    
    UFUNCTION(BlueprintPure)
    static void K2GetOwnedGameplayTagsIncludingComponents(AActor* Actor, FGameplayTagContainer& TagContainer);
    
    UFUNCTION(BlueprintPure)
    static bool K2GetOwnedGameplayTags(UObject* Object, FGameplayTagContainer& TagContainer);
    
    UFUNCTION(BlueprintCallable)
    static void K2GetAllOwnedGameplayTags(FGameplayTagContainer& OutTags, AActor* OtherActor, UPrimitiveComponent* OtherComponent, const UDamageType* DamageType, const FHitResult& HitResult, UObject* IgnoredObject);
    
    UFUNCTION(BlueprintCallable)
    static bool ClearGameplayTags(UObject* Object, bool bUpdateStimuli);
    
    UFUNCTION(BlueprintCallable)
    static void AppendGameplayTags(UObject* Object, const FGameplayTagContainer& Other, bool bUpdateStimuli);
    
    UFUNCTION(BlueprintCallable)
    static bool AddGameplayTag(UObject* Object, FGameplayTag Tag, bool bLeaf, bool bUpdateStimuli);
    
};

