#pragma once
#include "CoreMinimal.h"
#include "TWDWidgetComponent.h"
#include "SDIInteractionDescription.h"
#include "TWDInteractionWidgetComponent.generated.h"

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTWDInteractionWidgetComponent : public UTWDWidgetComponent {
    GENERATED_BODY()
public:
    UTWDInteractionWidgetComponent();
    UFUNCTION(BlueprintCallable)
    void SetDescriptions(const TArray<FSDIInteractionDescription>& Descriptions);
    
    UFUNCTION(BlueprintPure)
    TArray<FSDIInteractionDescription> GetDescriptions() const;
    
    UFUNCTION(BlueprintCallable)
    void ClearDescriptions();
    
};

