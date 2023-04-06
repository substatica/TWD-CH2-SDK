#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDInteractiveActor.h"
#include "TWDWeaponActorAttachmentEditor.generated.h"

class USceneComponent;
class ASDIWeaponActor;

UCLASS()
class ATWDWeaponActorAttachmentEditor : public ATWDInteractiveActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* WeaponAttach;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ASDIWeaponActor> WeaponActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxWeaponDistance;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIWeaponActor* WeaponActor;
    
public:
    ATWDWeaponActorAttachmentEditor(const FObjectInitializer& ObjectInitializer);
};

