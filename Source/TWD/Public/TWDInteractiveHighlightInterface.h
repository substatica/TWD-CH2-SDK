#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Interface.h"
#include "ETWDInteractionType.h"
#include "TWDInteractiveHighlightInterface.generated.h"

class USceneComponent;
class ASDIInteractiveHighlightManager;
class ATWDInteractiveHighlightActor;

UINTERFACE(Blueprintable)
class UTWDInteractiveHighlightInterface : public UInterface {
    GENERATED_BODY()
};

class ITWDInteractiveHighlightInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent)
    void UpdateHighlightActor(ATWDInteractiveHighlightActor* HighlightActor, float DeltaSeconds, ASDIInteractiveHighlightManager* Manager, USceneComponent* Component, bool bAnyInteractions, bool bLeftHandClose, bool bLeftHandRanged, bool bRightHandClose, bool bRightHandRanged) const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool ShowHighlight(ASDIInteractiveHighlightManager* Manager, USceneComponent* Component, bool bAnyInteractions, bool bLeftHandClose, bool bLeftHandRanged, bool bRightHandClose, bool bRightHandRanged) const;
    
    UFUNCTION(BlueprintNativeEvent)
    void InitHighlightActor(ATWDInteractiveHighlightActor* HighlightActor, ASDIInteractiveHighlightManager* Manager, USceneComponent* Component, bool bAnyInteractions, bool bLeftHandClose, bool bLeftHandRanged, bool bRightHandClose, bool bRightHandRanged) const;
    
    UFUNCTION(BlueprintNativeEvent)
    ETWDInteractionType GetHighlightType(ASDIInteractiveHighlightManager* Manager, USceneComponent* Component, bool bAnyInteractions, bool bLeftHandClose, bool bLeftHandRanged, bool bRightHandClose, bool bRightHandRanged) const;
    
    UFUNCTION(BlueprintNativeEvent)
    FTransform GetHighlightTransform(ASDIInteractiveHighlightManager* Manager, USceneComponent* Component, const FTransform& InTransform, const FTransform& CameraTransform, bool bCollide) const;
    
};

