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
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DebounceTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MinPhysicalInteractPushTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float PhysicalInteractPushThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float PhysicalInteractPushReleaseThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float PhysicalInteractMagnetEngageDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float PhysicalInteractMagnetDisengageDistance;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bIncludeWidgetInteractions;
    
    UPROPERTY(EditDefaultsOnly)
    bool bEnablePhysicsCollision;
    
    UPROPERTY(EditDefaultsOnly)
    bool bPhysicsCollisionExtendBackToHand;
    
    UPROPERTY(EditDefaultsOnly)
    float PhysicsCollisionShrinkage;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult PhysicalInteractResult;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DebounceTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bPhysicalInteractionPushed;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PhysicalInteractionPushPosition;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FHitResult PhysicalInteractPushCollision;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bPhysicalInteractPushCollisionValid;
    
    UPROPERTY(BlueprintReadWrite, Transient)
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

