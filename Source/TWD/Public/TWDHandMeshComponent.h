#pragma once
#include "CoreMinimal.h"
#include "SDIHandMeshComponent.h"
#include "TWDHandMeshComponent.generated.h"

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTWDHandMeshComponent : public USDIHandMeshComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditDefaultsOnly)
    float StabDragLocationPIDScalar;
    
    UPROPERTY(EditDefaultsOnly)
    float WindedLocationPIDScalar;
    
    UPROPERTY(EditDefaultsOnly)
    float WindedRotationPIDScalar;
    
    UPROPERTY(EditDefaultsOnly)
    float HoldingDraggedRagdollMinMass;
    
    UPROPERTY(EditDefaultsOnly)
    float HoldingDraggedRagdollAngularDamping;
    
    UPROPERTY(EditDefaultsOnly)
    float HoldingDraggedRagdollLinearDamping;
    
    UPROPERTY(Transient)
    bool bLastHoldingDraggedRagdollState;
    
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    float CachedPreHoldingDraggedRagdollMass;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CachedPreHoldingDraggedRagdollAngularDamping;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CachedPreHoldingDraggedRagdollLinearDamping;
    
public:
    UTWDHandMeshComponent();
};

