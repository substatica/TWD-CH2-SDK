#pragma once
#include "CoreMinimal.h"
#include "SDIInteractiveActorData.generated.h"

class UObject;
class USDITriggerResistanceFeedbackEffect_Curve;

USTRUCT(BlueprintType)
struct SDIVRPLAYERPLUGIN_API FSDIInteractiveActorData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    UObject* HighlightFeedback;
    
    UPROPERTY(EditAnywhere)
    UObject* GripFeedback;
    
    UPROPERTY(EditAnywhere)
    UObject* InteractFeedback;
    
    UPROPERTY(EditAnywhere)
    UObject* PhysicalInteractFeedback;
    
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

