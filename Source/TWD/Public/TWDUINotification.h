#pragma once
#include "CoreMinimal.h"
#include "ETWDUINotificationType.h"
#include "TWDUINotification.generated.h"

class UAkAudioEvent;
class UTexture2D;

USTRUCT(BlueprintType)
struct TWD_API FTWDUINotification {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Transient)
    FText NotificationStatusText;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FText NotificationTitleText;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FText NotificationSubtitleText;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UTexture2D* CustomUIIcon;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    UAkAudioEvent* CustomUIAudio;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ETWDUINotificationType NotificationType;
    
    FTWDUINotification();
};

