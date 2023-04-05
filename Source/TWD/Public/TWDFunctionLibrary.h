#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"
#include "EFaction.h"
#include "DialogueFinishedDelegate.h"
#include "TWDTopic.h"
#include "TWDDialogueOption.h"
#include "EFactionReaction.h"
#include "TWDFunctionLibrary.generated.h"

class UObject;
class ATWDCharacter;
class ATWDPlayerController;
class UTWDDialogue;
class UAkRtpc;
class UTexture2D;
class UAkAudioEvent;
class ATWDSpawnManager;
class ATWDGameDirector;
class ATWDDialogueManager;
class ATWDAIDirector;
class ATWDCorpseManager;
class APlayerController;

UCLASS(BlueprintType)
class TWD_API UTWDFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UTWDFunctionLibrary();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void StopTriggerEffect(const UObject* WorldContextObject, EControllerHand ControllerHand);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void StopDialogue(const UObject* WorldContextObject, TSubclassOf<UTWDDialogue> Dialogue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetUIAkRTPCValueByRTPC(const UObject* WorldContextObject, const UAkRtpc* RTPC, float Value, int32 InterpolationTimeMs);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetUIAkRTPCValue(const UObject* WorldContextObject, const FString& RTPC, float Value, int32 InterpolationTimeMs);
    
    UFUNCTION(BlueprintCallable)
    static void SetForceMipLevelsToBeResident(UTexture2D* Texture, bool bForceMiplevelsToBeResident);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PostUIAkEvent(const UObject* WorldContextObject, UAkAudioEvent* AKEvent);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PlayTriggerEffectWeapon(const UObject* WorldContextObject, EControllerHand ControllerHand, float StartPosition, float EndPosition, float Strength);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PlayTriggerEffectVibration(const UObject* WorldContextObject, EControllerHand ControllerHand, float Position, float Frequency, float Amplitude);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PlayTriggerEffectFeedback(const UObject* WorldContextObject, EControllerHand ControllerHand, float Position, float Strength);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UTWDDialogue* PlayDialogue(const UObject* WorldContextObject, TSubclassOf<UTWDDialogue> Dialogue, const TArray<ATWDCharacter*>& Characters, ATWDPlayerController* DialogueInstigator, const FDialogueFinished& DialogueFinished);
    
    UFUNCTION(BlueprintPure)
    static bool NotEqual_TopicTopic(FTWDTopic A, FName B);
    
    UFUNCTION(BlueprintPure)
    static bool NotEqual_OptionOption(FTWDDialogueOption A, FName B);
    
    UFUNCTION(BlueprintPure)
    static bool LessEqual_FactionReactionFactionReaction(EFactionReaction A, EFactionReaction B);
    
    UFUNCTION(BlueprintPure)
    static bool Less_FactionReactionFactionReaction(EFactionReaction A, EFactionReaction B);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsPlayerInDialogue(const UObject* WorldContextObject, ATWDPlayerController* PlayerController);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsCharacterInDialogue(const UObject* WorldContextObject, ATWDCharacter* Character);
    
    UFUNCTION(BlueprintPure)
    static bool GreaterEqual_FactionReactionFactionReaction(EFactionReaction A, EFactionReaction B);
    
    UFUNCTION(BlueprintPure)
    static bool Greater_FactionReactionFactionReaction(EFactionReaction A, EFactionReaction B);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ATWDSpawnManager* GetSpawnManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ATWDGameDirector* GetGameDirector(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static EFactionReaction GetFactionReaction(const UObject* WorldContextObject, EFaction MyFaction, EFaction TheirFaction);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ATWDDialogueManager* GetDialogueManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ATWDCorpseManager* GetCorpseManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ATWDAIDirector* GetAIDirector(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool EvaluateCriteria_Player(const UObject* WorldContextObject, TArray<FString> Criteria, APlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool EvaluateCriteria_Global(const UObject* WorldContextObject, TArray<FString> Criteria);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool EvaluateCriteria_Faction(const UObject* WorldContextObject, TArray<FString> Criteria, EFaction Faction);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool EvaluateCriteria_Character(const UObject* WorldContextObject, TArray<FString> Criteria, ATWDCharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    static void AudioDeviceStopPlayingID(int32 in_playingID);
    
    UFUNCTION(BlueprintPure)
    static void AppendStringMap(TMap<FString, FString> StringMapA, TMap<FString, FString> StringMapB, TMap<FString, FString>& OutStringMap);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddGlobalContext_String(const UObject* WorldContextObject, const FString& Key, const FString& Value);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddGlobalContext_Int(const UObject* WorldContextObject, const FString& Key, int32 Value);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddGlobalContext_Float(const UObject* WorldContextObject, const FString& Key, float Value);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddGlobalContext_Bool(const UObject* WorldContextObject, const FString& Key, bool bValue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddFactionContext_String(const UObject* WorldContextObject, EFaction Faction, const FString& Key, const FString& Value);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddFactionContext_Int(const UObject* WorldContextObject, EFaction Faction, const FString& Key, int32 Value);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddFactionContext_Float(const UObject* WorldContextObject, EFaction Faction, const FString& Key, float Value);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddFactionContext_Bool(const UObject* WorldContextObject, EFaction Faction, const FString& Key, bool bValue);
    
};

