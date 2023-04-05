#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ECharacterPose.h"
#include "ECharacterEmotion.h"
#include "ECharacterGesture.h"
#include "TWDCharacterSpeechData.h"
#include "DialogueLine.generated.h"

class UAkAudioEvent;

USTRUCT(BlueprintType)
struct TWD_API FDialogueLine : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FText Text;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ECharacterEmotion Emotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ECharacterPose Pose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ECharacterGesture Gesture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bSkippable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bForceTTSIfNone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FText Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString StageDirections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString Description;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSoftObjectPtr<UAkAudioEvent> AudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FTWDCharacterSpeechData SpeechData;
    
    UPROPERTY(Transient)
    UAkAudioEvent* CachedAudioEvent;
    
public:
    FDialogueLine();
};

