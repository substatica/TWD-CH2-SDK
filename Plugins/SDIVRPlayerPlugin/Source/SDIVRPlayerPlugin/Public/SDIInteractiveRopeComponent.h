#pragma once
#include "CoreMinimal.h"
#include "SDIRopeComponentHandGrip.h"
#include "SDIBlendOption.h"
#include "SDICoreCableComponent.h"
#include "SDIPIDControllerSettings.h"
#include "SDIInteractiveRopeComponent.generated.h"

class ASDIPlayerHand;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIInteractiveRopeComponent : public USDICoreCableComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bEnableGripTautConstraints;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float CosmeticGripExtension;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bEnableGripTautInterpolation;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    float GripTautStartDistance;
    
    UPROPERTY(EditAnywhere)
    FSDIBlendOption GripTautBlend;
    
    UPROPERTY(EditAnywhere)
    float GripTautStiffnessConstant;
    
    UPROPERTY(EditAnywhere)
    float GripTautDampeningRatio;
    
    UPROPERTY(EditAnywhere)
    bool bGripTautOverrideLocationPID;
    
    UPROPERTY(EditAnywhere)
    FSDIPIDControllerSettings GripTautLocationPID;
    
    UPROPERTY(EditAnywhere)
    bool bGripTautOverrideRotationPID;
    
    UPROPERTY(EditAnywhere)
    FSDIPIDControllerSettings GripTautRotationPID;
    
    UPROPERTY(Transient)
    bool bReactionInterfaceLocked;
    
    UPROPERTY(Transient)
    TMap<TWeakObjectPtr<ASDIPlayerHand>, FSDIRopeComponentHandGrip> HandGrips;
    
    UPROPERTY(Transient)
    bool bCreatedNonEnforcedTautConstraints;
    
public:
    USDIInteractiveRopeComponent();
};
