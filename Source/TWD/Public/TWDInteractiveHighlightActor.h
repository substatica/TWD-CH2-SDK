#pragma once
#include "CoreMinimal.h"
#include "SDISkinnedActorStaticMesh.h"
#include "TWDInteractiveHighlightActor.generated.h"

class UCurveFloat;
class UTWDInteractionWidgetComponent;

UCLASS()
class ATWDInteractiveHighlightActor : public ASDISkinnedActorStaticMesh {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDInteractionWidgetComponent* WidgetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float HighlightSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float UnHighlightSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UCurveFloat* ScaleCurve;
    
public:
    ATWDInteractiveHighlightActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateHighlight(bool bShowHighlight, float Highlight);
    
};

