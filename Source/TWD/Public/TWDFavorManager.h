#pragma once
#include "CoreMinimal.h"
#include "TWDFavorTier.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EMapTerritoryNodeType.h"
#include "TWDFavorDecaySettings.h"
#include "ETWDFavorReason.h"
#include "TWDFavorDecayState.h"
#include "TWDFavorManager.generated.h"

class UTWDSaveGame;
class UTWDExileOrderEvent;

UCLASS(Blueprintable)
class TWD_API UTWDFavorManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bEnabled;
    
protected:
    UPROPERTY(EditDefaultsOnly)
    FVector2D LocalFavorLimit;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FTWDFavorTier> LocalFavorTiers;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<EMapTerritoryNodeType, FName> MaxTierEventSublevelNamesByTerritory;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<FName, float> CommonLocalFavorDeltas;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FTWDFavorTier> GlobalFavorTiers;
    
    UPROPERTY(EditDefaultsOnly)
    FTWDFavorDecaySettings DecaySettings;
    
private:
    UPROPERTY(Transient)
    TMap<EMapTerritoryNodeType, FTWDFavorDecayState> FavorDecayStateByTerritory;
    
public:
    UTWDFavorManager();
    UFUNCTION(BlueprintCallable)
    float SetLocalFavor(EMapTerritoryNodeType Territory, float NewLocalFavor, ETWDFavorReason reason);
    
    UFUNCTION()
    void SaveToSaveData(UTWDSaveGame* SaveGame) const;
    
    UFUNCTION(BlueprintCallable)
    void RefreshLocalFavorTiers();
    
    UFUNCTION(BlueprintCallable, Exec)
    int32 RefreshGlobalFavorTier();
    
    UFUNCTION(BlueprintCallable)
    float RefreshGlobalFavor();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnLocalFavorTierAltered(EMapTerritoryNodeType Territory, int32 PrevLocalTierIndex, int32 CurrLocalTierIndex);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnGlobalFavorTierAltered(int32 PrevGlobalTierIndex, int32 CurrGlobalTierIndex);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnFavorAltered(EMapTerritoryNodeType Territory, float PrevLocalFavor, float CurrLocalFavor, float PrevGlobalFavor, float CurrGlobalFavor, ETWDFavorReason reason);
    
    UFUNCTION()
    void LoadFromSaveData(UTWDSaveGame* SaveGame);
    
    UFUNCTION(BlueprintPure)
    bool IsCurrentLocalFavorTierAtMaximum(EMapTerritoryNodeType Territory) const;
    
    UFUNCTION()
    void HandleOrderRemoval(const UTWDExileOrderEvent* OrderEvent);
    
    UFUNCTION()
    void HandleNewDay();
    
    UFUNCTION(BlueprintPure)
    int32 GetLocalFavorTierIndex(float InLocalFavor) const;
    
    UFUNCTION(BlueprintPure)
    int32 GetLocalFavorTierCount() const;
    
    UFUNCTION(BlueprintPure)
    FTWDFavorTier GetLocalFavorTier(int32 TierIndex) const;
    
    UFUNCTION(BlueprintPure)
    float GetLocalFavor(EMapTerritoryNodeType Territory) const;
    
    UFUNCTION(BlueprintPure)
    int32 GetGlobalFavorTierIndex(float InGlobalFavor) const;
    
    UFUNCTION(BlueprintPure)
    int32 GetGlobalFavorTierCount() const;
    
    UFUNCTION(BlueprintPure)
    FTWDFavorTier GetGlobalFavorTier(int32 TierIndex) const;
    
    UFUNCTION(BlueprintPure)
    float GetGlobalFavor() const;
    
    UFUNCTION(BlueprintPure)
    FTWDFavorTier GetCurrentLocalFavorTier(EMapTerritoryNodeType Territory, int32& CurrentTierIndex) const;
    
    UFUNCTION(BlueprintPure)
    FTWDFavorTier GetCurrentGlobalFavorTier() const;
    
protected:
    UFUNCTION(BlueprintPure)
    FTWDFavorDecayState GetCurrentDecayState(EMapTerritoryNodeType Territory) const;
    
public:
    UFUNCTION(BlueprintPure)
    float GetCommonLocalFavorDelta(FName CommonDeltaKey) const;
    
    UFUNCTION(BlueprintCallable)
    float DebugSetGlobalFavor(float NewGlobalFavor);
    
    UFUNCTION(BlueprintCallable)
    void DebugSetDecayState(EMapTerritoryNodeType Territory, FTWDFavorDecayState DecayState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void DebugLogFavor() const;
    
    UFUNCTION(BlueprintCallable)
    void DebugClearLocalFavor();
    
    UFUNCTION(BlueprintCallable)
    float DebugAlterGlobalFavor(float GlobalFavorDelta);
    
    UFUNCTION(BlueprintCallable)
    float ApplyLocalFavorDecay(EMapTerritoryNodeType Territory);
    
    UFUNCTION(BlueprintCallable)
    float ApplyCommonLocalFavorDelta(EMapTerritoryNodeType Territory, FName CommonDeltaKey, ETWDFavorReason reason);
    
    UFUNCTION(BlueprintCallable)
    float AlterLocalFavor(EMapTerritoryNodeType Territory, float LocalFavorDelta, ETWDFavorReason reason);
    
};

