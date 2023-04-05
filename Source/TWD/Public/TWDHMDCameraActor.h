#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "Camera/CameraActor.h"
#include "TWDUINotification.h"
#include "EFaction.h"
#include "SavedLookatNotebookData.h"
#include "EFactionReaction.h"
#include "TWDHMDCameraActor.generated.h"

class ATWDPlayerCharacter;
class ATWDPlayerController;
class USphereComponent;
class UTWDWidgetComponent;
class ASDIHeldActor;
class UTWDSubtitleWidget;
class UAkAudioEvent;
class UTexture2D;
class UTWDDialogueSelectionWidget;
class UTWDDialogueAvailabilityWidget;
class UTWDExileOrderEvent;
class UTWDRecipe;
class ASDIInventoryActor;

UCLASS()
class ATWDHMDCameraActor : public ACameraActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USphereComponent* HeadCollisionSphere;
    
    UPROPERTY(Transient)
    TArray<FTWDUINotification> TaskNotificationQueue;
    
    UPROPERTY(BlueprintReadOnly)
    bool bGrappleUIEnabled;
    
    UPROPERTY(BlueprintReadOnly)
    bool bGutsModeUIEnabled;
    
    UPROPERTY(BlueprintReadOnly)
    bool bFoodConsumptionUIEnabled;
    
    UPROPERTY(BlueprintReadOnly)
    bool bPlayerHealthUIEnabled;
    
    UPROPERTY(BlueprintReadOnly)
    bool bPlayerInventoryMessageUIEnabled;
    
    UPROPERTY(BlueprintReadOnly)
    bool bWaveModeCombatUIEnabled;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    ATWDPlayerCharacter* PlayerCharacter;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float PlayerHealthPercent;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float PlayerStaminaPercent;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float LastPlayerHealthPercent;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float LastPlayerStaminaPercent;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bLastSaveRunnableIsActive;
    
private:
    UPROPERTY(Instanced, VisibleAnywhere)
    UTWDWidgetComponent* SubtitleWidgetComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UTWDWidgetComponent* DialogueSelectionWidgetComponent;
    
    UPROPERTY(Instanced, VisibleAnywhere)
    UTWDWidgetComponent* DialogueAvailabilityWidgetComponent;
    
    UPROPERTY(EditDefaultsOnly)
    FVector DialogueSelectionWidgetOffset;
    
    UPROPERTY(EditDefaultsOnly)
    FVector DialogueAvailabilityWidgetOffset;
    
    UPROPERTY(Transient)
    float TimeRemainingPercent;
    
    UPROPERTY(EditDefaultsOnly)
    float DialogueWidgetLocationSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float DialogueWidgetRotationSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    bool bFixedDialogueWidgetScale;
    
    UPROPERTY(EditDefaultsOnly)
    bool bAlwaysSnapDialogueWidget;
    
    UPROPERTY(EditDefaultsOnly)
    int32 TranslucencySortPriority;
    
    UPROPERTY(EditDefaultsOnly)
    float SubtitleAutoDepthMaxDistance;
    
    UPROPERTY(EditDefaultsOnly)
    float SubtitleAutoDepthInterpolationSpeed;
    
    UPROPERTY(EditDefaultsOnly)
    float SubtitleAutoDepthTraceInterval;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<ASDIHeldActor>> ShowHealthStaminaHeldActorClasses;
    
    UPROPERTY(EditDefaultsOnly)
    TArray<FName> ShowHealthStaminaTemporaryBuffs;
    
    UPROPERTY(Instanced, Transient)
    UTWDSubtitleWidget* SubtitleWidget;
    
    UPROPERTY(Instanced, Transient)
    UTWDDialogueSelectionWidget* DialogueSelectionWidget;
    
    UPROPERTY(Instanced, Transient)
    UTWDDialogueAvailabilityWidget* DialogueAvailabilityWidget;
    
    UPROPERTY(Transient)
    bool bDialogueSelectionWidgetWasVisible;
    
    UPROPERTY(Transient)
    bool bDialogueAvailabilityWidgetWasVisible;
    
public:
    ATWDHMDCameraActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateFadeProxy(float FadeAmount, float ElapsedTime);
    
    UFUNCTION(BlueprintImplementableEvent)
    void ShowSaveGameNotification();
    
    UFUNCTION(BlueprintPure)
    bool ShouldShowStatsBuffs() const;
    
    UFUNCTION(BlueprintPure)
    bool ShouldShowHealthStamina() const;
    
    UFUNCTION(BlueprintCallable)
    void SelectDialogueSelectionWithName(const FName& OptionName);
    
    UFUNCTION(BlueprintCallable)
    void QueueCustomNotification(FText Status, FText Title, UTexture2D* CustomUIIcon, UAkAudioEvent* CustomUIAudio);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnUpdateExileOrderEvent(UTWDExileOrderEvent* OrderEvent);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnTrackRecipe(TSubclassOf<UTWDRecipe> RecipeClass);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnTrackedRecipeUpdate(TSubclassOf<UTWDRecipe> RecipeClass);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnScavengingListUpdated();
    
    UFUNCTION(BlueprintNativeEvent)
    void OnSaveNote(FSavedLookatNotebookData NoteData);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnNotificationComplete();
    
    UFUNCTION(BlueprintNativeEvent)
    void OnNewNotification(FTWDUINotification Notification);
    
public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnFactionReputationChanged(EFaction Faction, float Reputation);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnFactionReactionChanged(EFaction Faction, EFactionReaction NewReaction, EFactionReaction PreviousReaction);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnAssignExileOrderEvent(UTWDExileOrderEvent* OrderEvent);
    
    UFUNCTION(BlueprintImplementableEvent)
    void NotifyItemStored(ASDIInventoryActor* InventoryActor);
    
    UFUNCTION(BlueprintPure)
    bool IsDialogueSkipVisible() const;
    
    UFUNCTION(BlueprintImplementableEvent)
    void HideSaveGameNotification();
    
    UFUNCTION(BlueprintPure)
    ATWDPlayerController* GetPlayerController() const;
    
    UFUNCTION(BlueprintPure)
    float GetDialogueSkipPercent() const;
    
    UFUNCTION(BlueprintPure)
    ATWDPlayerCharacter* GetControlledPlayerCharacter() const;
    
};

