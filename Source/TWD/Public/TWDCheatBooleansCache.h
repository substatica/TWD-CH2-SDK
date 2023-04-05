#pragma once
#include "CoreMinimal.h"
#include "TWDCheatBooleansCache.generated.h"

USTRUCT(BlueprintType)
struct FTWDCheatBooleansCache {
    GENERATED_BODY()
public:
    UPROPERTY()
    bool bShowDebugAIPerceptionData;
    
    UPROPERTY()
    bool bLightDependentSightStimuli;
    
    UPROPERTY()
    bool bDisplayVolumeticLightData;
    
    UPROPERTY()
    bool bDisplaySightStimCalculations;
    
    UPROPERTY()
    bool bDisplayFootstepSounds;
    
    UPROPERTY()
    bool bNoGrappling;
    
    UPROPERTY()
    bool bGodMode;
    
    UPROPERTY()
    bool bNoDurabilityLoss;
    
    UPROPERTY()
    bool bPlayerGripLock;
    
    UPROPERTY()
    bool bIgnorePlayerStim;
    
    UPROPERTY()
    bool bNoPlayerDeath;
    
    UPROPERTY()
    bool bFlashlightInfinite;
    
    UPROPERTY()
    bool bDisableStimulusSharing;
    
    UPROPERTY()
    bool bDisableHMDCollisions;
    
    UPROPERTY()
    bool bDisableNoteConsumption;
    
    UPROPERTY()
    bool bPauseAlwaysAllowed;
    
    UPROPERTY()
    bool bForceNightMode;
    
    UPROPERTY()
    bool bGoofyModeLowGravity;
    
    UPROPERTY()
    bool bGoofyModeTurbo;
    
    UPROPERTY()
    bool bDemiGod;
    
    UPROPERTY()
    bool bInfiniteStamina;
    
    TWD_API FTWDCheatBooleansCache();
};

