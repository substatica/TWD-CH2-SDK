#pragma once
#include "CoreMinimal.h"
#include "SDIInteractiveActorData.generated.h"

class UHapticFeedbackEffect_Base;
class USDITriggerResistanceFeedbackEffect_Curve;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIInteractiveActorData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    UHapticFeedbackEffect_Base* HighlightFeedback;
    
    UPROPERTY(EditAnywhere)
    UHapticFeedbackEffect_Base* GripFeedback;
    
    UPROPERTY(EditAnywhere)
    UHapticFeedbackEffect_Base* InteractFeedback;
    
    UPROPERTY(EditAnywhere)
    UHapticFeedbackEffect_Base* PhysicalInteractFeedback;
    
    UPROPERTY(EditAnywhere)
    bool bUseInteractTriggerResistanceCurveForHighlightedInteractions;
    
    UPROPERTY(EditAnywhere)
    USDITriggerResistanceFeedbackEffect_Curve* InteractTriggerResistanceCurve;
    
    UPROPERTY(EditAnywhere)
    bool bInteractiveGripOverride;
    
    UPROPERTY(EditAnywhere)
    bool bDisableNonVRInteractionMovement;
    
    UPROPERTY(EditAnywhere)
    bool bDisableNonVRObjectInteraction;
    
    FSDIInteractiveActorData();
};

