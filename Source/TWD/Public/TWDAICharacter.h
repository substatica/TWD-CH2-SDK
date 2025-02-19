#pragma once
#include "CoreMinimal.h"
#include "TWDCharacter.h"
#include "UObject/NoExportTypes.h"
#include "EStatusIconState.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ETWDCharacterAIAnimationTypes.h"
#include "ETWDCharacterHitDirection.h"
#include "GameplayTagContainer.h"
#include "TWDAIReactionStateData.h"
#include "Curves/CurveFloat.h"
#include "Engine/DataTable.h"
#include "EGOAIProperties.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "TWDAICharacter.generated.h"

class UTextRenderComponent;
class UAIPerceptionStimuliSourceComponent;
class UMaterialBillboardComponent;
class ATWDAIPerceptionModifierVolume;
class UMaterialInstance;
class UAnimSequence;
class AVolume;
class ASDIPath;
class ASDIInventoryActor;

UCLASS()
class TWD_API ATWDAICharacter : public ATWDCharacter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bFullyAwareOfPlayerUntilSeen;
    
    UPROPERTY(Transient)
    bool bHasSeenPlayer;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced)
    UTextRenderComponent* DebugInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced)
    UAIPerceptionStimuliSourceComponent* AIPerceptionStimuliSource;
    
    UPROPERTY(Instanced)
    UMaterialBillboardComponent* ThreatMeterIconComponent;
    
    UPROPERTY()
    EStatusIconState StatusIconState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UMaterialInstance* ThreatMeterIconMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UMaterialInstance* DialogueIconMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ThreatMeterFadeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ThreatMeterAttackHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ThreatMeterIconScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector ThreatMeterIconOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FLinearColor ThreatMeterColorLow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FLinearColor ThreatMeterColorHigh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FLinearColor ThreatMeterColorAlert;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FLinearColor FearMeterColorLow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FLinearColor FearMeterColorHigh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FLinearColor FearMeterColorPanic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bThreatMeterEnabled;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TMap<ETWDCharacterAIAnimationTypes, UAnimSequence*> AnimationSequences;
    
    UPROPERTY(EditDefaultsOnly)
    FName CurrentTargetKeyName;
    
    UPROPERTY(EditDefaultsOnly)
    FName SuspicionStateKeyName;
    
    UPROPERTY(EditAnywhere)
    TArray<float> UROVisibleDistanceFactors;
    
    UPROPERTY(EditAnywhere)
    TArray<AVolume*> StimIgnoreVolumes;
    
    UPROPERTY(EditAnywhere)
    TArray<AVolume*> StimAllowVolumes;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bDebugShowSignificance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bDebugShowLOD;
    
public:
    UPROPERTY(Transient)
    int32 AliveAvoidanceGroupMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 DeadAvoidanceGroupMask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ASDIPath* PathObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FGameplayTagContainer PathTags;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 CurrentPathId;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 PreviousPathID;
    
    UPROPERTY(EditAnywhere)
    TArray<FTWDAIReactionStateData> ReactionStateDataList;
    
    UPROPERTY(EditDefaultsOnly)
    float BaseHitProbability;
    
    UPROPERTY(EditAnywhere)
    float HitAccuracyMultiplier;
    
    UPROPERTY(EditDefaultsOnly)
    FRuntimeFloatCurve HitAccuracyScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAlwaysSignificant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bNeverSignificant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MenaceRadius;
    
    UPROPERTY(BlueprintReadWrite)
    ATWDAIPerceptionModifierVolume* PlayerPerceptionModifierVolume;
    
    UPROPERTY(BlueprintReadWrite)
    bool bRecentlySawPlayerInModifierVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float NightModeAccuracyModifier;
    
    UPROPERTY(EditDefaultsOnly)
    FRuntimeFloatCurve CurrentDayAccuracyCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient)
    uint8 bIsInGrappleProcess: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FDataTableRowHandle PersonalityDataTableRowHandle;
    
    UPROPERTY(BlueprintReadWrite)
    FEGOAIProperties EGOProperties;
    
    ATWDAICharacter(const FObjectInitializer& ObjectInitializer);
    UFUNCTION()
    void UpdateThreatMeter(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterMenace();
    
    UFUNCTION(BlueprintCallable)
    void UnregisterHunting();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ThrowGrenade();
    
    UFUNCTION(BlueprintCallable)
    void SetStimIgnoreVolumes(TArray<AVolume*> Volumes);
    
    UFUNCTION(BlueprintCallable)
    void SetStimAllowVolumes(TArray<AVolume*> Volumes);
    
    UFUNCTION(BlueprintCallable)
    void SetDebugTextEnable(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void SetDebugTextColor(FColor Color);
    
    UFUNCTION(BlueprintCallable)
    void SetDebugText(const FText& Text);
    
    UFUNCTION(BlueprintImplementableEvent)
    void SetAggroDebugTextSize(float Size);
    
    UFUNCTION(BlueprintImplementableEvent)
    void SetAggroDebugTextEnable(bool bEnable);
    
    UFUNCTION(BlueprintImplementableEvent)
    void SetAggroDebugTextColor(FColor Color);
    
    UFUNCTION(BlueprintImplementableEvent)
    void SetAggroDebugText(const FText& Text);
    
    UFUNCTION(BlueprintCallable)
    void ResetHunting();
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllPathTags();
    
    UFUNCTION(BlueprintCallable)
    void RegisterMenace();
    
    UFUNCTION(BlueprintCallable)
    void RegisterHunting(ATWDCharacter* Hunted);
    
protected:
    UFUNCTION()
    void OnPauseAI(bool bPause);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsStimLocationAllowed(const FVector& Location) const;
    
    UFUNCTION(BlueprintPure)
    bool IsLocationInStimIgnoreVolume(const FVector& Location) const;
    
    UFUNCTION(BlueprintPure)
    bool IsLocationInStimAllowVolume(const FVector& Location) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ASDIInventoryActor* HoldGrenadeFromInventory();
    
    UFUNCTION(BlueprintPure)
    bool HasBeenLongSinceLastSeenByPlayer(float ThresholdSeconds) const;
    
    UFUNCTION(BlueprintPure)
    TArray<AVolume*> GetStimIgnoreVolumes() const;
    
    UFUNCTION(BlueprintPure)
    TArray<AVolume*> GetStimAllowVolumes() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FTWDAIReactionStateData> GetReactionStateDataList();
    
    UFUNCTION(BlueprintPure)
    UAnimSequence* GetAnimSequence(const ETWDCharacterAIAnimationTypes AnimType, bool& ResultFound) const;
    
    UFUNCTION(BlueprintImplementableEvent)
    void DebugShowAggravation(bool bShow);
    
    UFUNCTION(BlueprintPure)
    static void ComputeDirection(const FVector& Forward, const FVector& Right, const FVector& DirectionWorldSpace, FRotator& OutForwardRotator, ETWDCharacterHitDirection& OutHitDirection);
    
    UFUNCTION(BlueprintCallable)
    void ClearStimVolumes();
    
    UFUNCTION(BlueprintCallable)
    void ClearStimIgnoreVolumes();
    
    UFUNCTION(BlueprintCallable)
    void ClearStimAllowVolumes();
    
    UFUNCTION(BlueprintCallable)
    void AddPathTag(const FGameplayTag& PathTag);
    
};

