#pragma once
#include "CoreMinimal.h"
#include "SDICoreGameState.h"
#include "TWDGameState_OnRingBellsDelegate.h"
#include "Engine/EngineTypes.h"
#include "TWDGameState_OnResetBellsDelegate.h"
#include "TWDGameState_OnPreRingBellsDelegate.h"
#include "BellAlarmDelegate.h"
#include "HordeTimerChangedDelegate.h"
#include "TWDGameState.generated.h"

class ULevel;
class UWorld;

UCLASS(Blueprintable)
class TWD_API ATWDGameState : public ASDICoreGameState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultTimeUntilBells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BellAlarmTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreHordeBellTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreHordeAutosaveCutoff;
       
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ActiveSurvivorsMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ActiveTotalCharactersMax;
    
    UPROPERTY(EditAnywhere, Transient)
    int32 SurvivorMaxSeenSignifanceBucket[4];
    
    UPROPERTY(EditAnywhere, Transient)
    int32 WalkerMaxSeenSignifanceBucket[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReviveBeforeHordeTimerDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReviveAfterHordeTimerDelay;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle HordeTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle PreHordeTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle BellAlarmTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle HordeAchievementTimerHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTWDGameState_OnResetBells OnResetBellsDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTWDGameState_OnRingBells OnRingBellsDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTWDGameState_OnPreRingBells OnPreRingBellsDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBellAlarm BellAlarm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHordeTimerChanged HordeTimerChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHordeTimerChanged PreHordeTimerChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHordeTimerChanged AlarmTimerChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HordeTimerStartTimestamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LeastSignificance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxFullsignificanceAllowed;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxCharactersSwitchAllowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 CurrentCharactersSwitch;
    
    UPROPERTY(Transient)
    bool bOnGameActivityActivationRequested;
    
    ATWDGameState(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
    void StopMusic();
    
    UFUNCTION(BlueprintCallable)
    void StopHordeTimer();
    
    UFUNCTION(BlueprintCallable)
    void RushBells(float NewDelay);
    
    UFUNCTION(BlueprintCallable)
    void ReviveTimer();
    
    UFUNCTION()
    void OnPreHordeTimerComplete();
    
    UFUNCTION()
    void OnLevelChanged(ULevel* Level, UWorld* World);
    
    UFUNCTION()
    void OnHordeTimerComplete();
    
    UFUNCTION()
    void OnBellAlarmTimerComplete() const;
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastExecuteRingBellsDelegate();
    
public:
    UFUNCTION(BlueprintCallable)
    void K2_StartHordeTimer(float NewDelay);
    
    UFUNCTION(BlueprintPure)
    bool IsHordeTimerActive() const;
    
    UFUNCTION(BlueprintPure)
    bool IsAlarmTimerActive() const;
    
    UFUNCTION(BlueprintPure)
    float GetTimeUntilBells() const;
    
    UFUNCTION(BlueprintPure)
    float GetTimeUntilBellAlarm() const;
    
    UFUNCTION(BlueprintCallable)
    float GetStartTimeUntilBells();
    
    UFUNCTION(BlueprintPure)
    float GetPreHordeAutosaveCutoff() const;
    
    UFUNCTION()
    bool GetCharacterSwitchToken();
    
};

