#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EFaction.h"
#include "PauseAIDelegateDelegate.h"
#include "SDICoreGameMode.h"
#include "TWDQueuedExplosionDelegateDelegate.h"
#include "Engine/EngineTypes.h"
#include "TWDQueuedExplosion.h"
#include "TWDFactionInfo.h"
#include "TWDGameMode.generated.h"

class APawn;
class UTWDAIManager;
class ATWDGameDirector;
class UTWDAnimIdManager;
class UBehaviorTree;
class AController;
class ATWDCharacter;
class UDamageType;
class AActor;
class ATWDAIController;

UCLASS(NonTransient)
class TWD_API ATWDGameMode : public ASDICoreGameMode {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSoftClassPtr<APawn> DefaultNonVRPawnClass;
    
    UPROPERTY(Transient)
    FName MatchSubState;
    
    UPROPERTY(Transient)
    FTimerHandle QueuedExplosionTimerHandle;
    
    UPROPERTY(Transient)
    TArray<FTWDQueuedExplosion> QueuedExplosions;
    
    UPROPERTY(Transient)
    bool bProcessingQueuedExplosions;
    
public:
    UPROPERTY(BlueprintAssignable)
    FPauseAIDelegate PauseAIDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<UTWDAIManager> AIManagerClass;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bEnableSleepingAISystem;
    
private:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<ATWDGameDirector> GameDirectorBlueprint;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<EFaction, FTWDFactionInfo> FactionInfo;
    
    UPROPERTY(EditDefaultsOnly)
    bool bNotebookEnabled;
    
    UPROPERTY(Transient)
    ATWDGameDirector* GameDirector;
    
    UPROPERTY(Transient)
    UTWDAIManager* AIManager;
    
    UPROPERTY(Transient)
    UTWDAnimIdManager* AnimIdManager;
    
public:
    UPROPERTY(EditDefaultsOnly)
    TArray<UBehaviorTree*> PreloadBehaviorTree;
    
    ATWDGameMode(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintNativeEvent)
    void StartBells();
    
    UFUNCTION(BlueprintCallable)
    void SetMatchSubState(FName NewState);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveQueuedExplosion(const FTWDQueuedExplosionDelegate& ExplosionDelegate);
    
    UFUNCTION(BlueprintCallable)
    static void QueueExplosion(AController* EventInstigator, const FTWDQueuedExplosionDelegate& ExplosionDelegate);
    
protected:
    UFUNCTION()
    void ProcessQueuedExplosions();
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnMatchSubStateSet();
    
    UFUNCTION(BlueprintNativeEvent)
    void OnCharacterDeath(ATWDCharacter* Character, float PrevHealth, TSubclassOf<UDamageType> DamageTypeClass, AActor* DamageCauser);
    
    UFUNCTION(BlueprintPure)
    bool IsNotebookEnabled() const;
    
    UFUNCTION(BlueprintPure)
    static bool IsExplosionQueued(const FTWDQueuedExplosionDelegate& ExplosionDelegate);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitializeAIByGameMode(ATWDAIController* AIController);
    
    UFUNCTION(BlueprintCallable)
    UTWDAnimIdManager* GetAnimIdManager();
    
    UFUNCTION(BlueprintCallable)
    UTWDAIManager* GetAIManager();
    
};

