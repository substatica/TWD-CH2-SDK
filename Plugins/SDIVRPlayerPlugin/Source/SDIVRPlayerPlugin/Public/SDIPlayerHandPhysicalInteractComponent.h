#pragma once
#include "CoreMinimal.h"
#include "SDIPlayerHandInteractComponent.h"
#include "Engine/EngineTypes.h"
#include "PhysicsEngine/ConstraintInstance.h"
#include "SDIAuxTickFunction.h"
#include "SDIPlayerHandPhysicalInteractComponent.generated.h"

class UWidgetInteractionComponent;
class UBodySetup;
class UObject;
class AActor;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDIVRPLAYERPLUGIN_API USDIPlayerHandPhysicalInteractComponent : public USDIPlayerHandInteractComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float DebounceTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MinPhysicalInteractPushTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float PhysicalInteractPushThreshold;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float PhysicalInteractPushReleaseThreshold;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float PhysicalInteractMagnetEngageDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float PhysicalInteractMagnetDisengageDistance;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    bool bIncludeWidgetInteractions;
    
    UPROPERTY(EditDefaultsOnly)
    bool bEnablePhysicsCollision;
    
    UPROPERTY(EditDefaultsOnly)
    bool bPhysicsCollisionExtendBackToHand;
    
    UPROPERTY(EditDefaultsOnly)
    float PhysicsCollisionShrinkage;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FHitResult PhysicalInteractResult;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float DebounceTimer;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bPhysicalInteractionPushed;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float PhysicalInteractionPushPosition;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    FHitResult PhysicalInteractPushCollision;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bPhysicalInteractPushCollisionValid;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    float PhysicalInteractPushTime;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<TWeakObjectPtr<UWidgetInteractionComponent>> CachedWidgetInteractComponents;
    
    UPROPERTY()
    FSDIAuxTickFunction PhysicalCollisionTick;
    
    UPROPERTY(Transient)
    UBodySetup* PhysicalCollisionBodySetup;
    
    UPROPERTY(Transient)
    FConstraintProfileProperties PhysicalCollisionConstraintSettings;
    
public:
    USDIPlayerHandPhysicalInteractComponent();
protected:
    UFUNCTION()
    void TickPhysicalCollision(UObject* TickOwner, float DeltaTime);
    
public:
    UFUNCTION(BlueprintPure)
    FHitResult K2GetPhysicalInteractResult() const;
    
    UFUNCTION(BlueprintPure)
    AActor* GetGetPhysicalInteractActor() const;
    
};

