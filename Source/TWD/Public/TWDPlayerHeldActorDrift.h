#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "TWDPlayerHeldActorDrift.generated.h"

class UCurveFloat;

UCLASS(BlueprintType, Transient)
class UTWDPlayerHeldActorDrift : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DefaultItemDistanceFromCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ItemDistanceFromCameraMultiplierMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ItemDistanceFromCameraMultiplierMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MaxDriftOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UCurveFloat* DriftBoundaryFactorCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FVector DriftBoundaryPushbackStrength;
    
protected:
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Drift;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector ItemPosition;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector CurrentVelocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector VelocityInterp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator CurrentAimRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator AimRotationVel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ItemDistanceFromCamera;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ItemDistanceFrom_Z_Axis;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CentripetalAccelerationFromYawInterp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CentripetalAccelerationFromPitchInterp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator TangentialVelocity;
    
public:
    UTWDPlayerHeldActorDrift();
    UFUNCTION(BlueprintCallable)
    void UpdateDrift(const FVector& Vel, const FRotator& AimRot, const float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable)
    void Initialize(const FVector& Vel, const FRotator& AimRot);
    
    UFUNCTION(BlueprintPure)
    FRotator GetTangentialVelocity() const;
    
};

