#pragma once
#include "CoreMinimal.h"
#include "TWDUserWidget.h"
#include "SDICameraSettings.h"
#include "UObject/NoExportTypes.h"
#include "TWDNonVRInteractionPrompt.h"
#include "TWDNonVRInteractionWidget.generated.h"

class ASDICorePlayerController;

UCLASS(EditInlineNew)
class TWD_API UTWDNonVRInteractionWidget : public UTWDUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDICameraSettings CameraSettings;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bUseNonVRCameraRotation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRotator NonVRCameraRotation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NonVRCameraRotationTime;
    
public:
    UTWDNonVRInteractionWidget();
    UFUNCTION()
    void UpdateInteraction();
    
    UFUNCTION()
    void StopInteraction();
    
    UFUNCTION()
    void StartInteraction();
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnUpdateInteraction();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnStopInteraction();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnStartInteraction();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnInteractionPromptsChanged(const TArray<FTWDNonVRInteractionPrompt>& NewPrompts);
    
public:
    UFUNCTION()
    void OnDeviceChanged(ASDICorePlayerController* PC, bool bIsUsingGamePad);
    
protected:
    UFUNCTION(BlueprintPure)
    TArray<FTWDNonVRInteractionPrompt> GatherInteractionPrompts() const;
    
};

