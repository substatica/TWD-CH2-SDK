#pragma once
#include "CoreMinimal.h"
#include "TWDNonVRInteractionWidget.h"
#include "TWDNonVRBackpackWidget.generated.h"

class ATWDBackpack;
class ASDIInventoryActor;

UCLASS(EditInlineNew)
class TWD_API UTWDNonVRBackpackWidget : public UTWDNonVRInteractionWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ATWDBackpack* BackpackActor;
    
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIInventoryActor* CurrentlySelectedItem;
    
public:
    UTWDNonVRBackpackWidget();
    UFUNCTION()
    void OnSelectedItemChanged(ASDIInventoryActor* NewItem);
    
};

