#pragma once
#include "CoreMinimal.h"
#include "SDICharacter.h"
#include "RFloat.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/SpringInterpolator.h"
#include "SDICharacterAdvanced.generated.h"

UCLASS()
class SDIVRPLAYERPLUGIN_API ASDICharacterAdvanced : public ASDICharacter {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    bool bUseVRFacingForMovement;
    
protected:
    UPROPERTY(EditDefaultsOnly)
    float BaseTurnRate;
    
    UPROPERTY(EditDefaultsOnly)
    float CrouchToCrawlHoldTime;
    
    UPROPERTY(EditDefaultsOnly)
    float SprintCancelMaxAngleOffsetDeg;
    
    UPROPERTY(EditDefaultsOnly)
    float SprintMaxAngleOffsetDeg;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float CrawlEyeHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat EyeHeightOffsetRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloat HMDEyeHeightAllowedRange;

    UPROPERTY(EditAnywhere)
    FFloatRK4SpringInterpolator EyeHeightSpring;
    
    UPROPERTY(EditAnywhere)
    FFloatRK4SpringInterpolator EyeHeightOffsetSpring;
    
    UPROPERTY(EditAnywhere)
    FFloatRK4SpringInterpolator EyeHeightGroundMovementSpring;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float EyeHeightGroundMovementSpringMaxOffset;

    UPROPERTY(EditAnywhere)
    FFloatRK4SpringInterpolator EyeHeightRopeMovementSpring;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float EyeHeightRopeMovementSpringMaxOffset;

    UPROPERTY(EditAnywhere)
    FFloatRK4SpringInterpolator EyeHeightLandingMovementSpring;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float EyeHeightLandingMovementSpringMaxOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float EyeHeightLandingMovementSpringMaxVel;

    UPROPERTY(EditAnywhere)
    FFloatRK4SpringInterpolator EyeHeightCapsuleOffsetSpring;

    UPROPERTY(BlueprintReadWrite, Transient)
    bool bAlwaysSprint;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bNeverCrouch;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bCtrlCrawl;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float CtrlCrouchTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DesiredEyeHeightOffset;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float DesiredEyeHeightOffsetFromFloor;
    
    UPROPERTY(Transient)
    float EyeHeightCapsuleAdjustment;
    
public:
    UPROPERTY(BlueprintReadWrite, ReplicatedUsing=OnRep_bRepIsCrawling)
    bool bRepIsCrawling;
    
    ASDICharacterAdvanced(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void UnCrawl(bool bClientSimulation);
    
    UFUNCTION(BlueprintCallable)
    void SetDesiredEyeHeightOffsetFromFloor(float Offset);
    
    UFUNCTION(BlueprintCallable)
    void SetDesiredEyeHeightOffset(float Offset, bool bReset);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStartCrawl(float HalfHeightAdjust, float ScaledHalfHeightAdjust);
    
protected:
    UFUNCTION()
    void OnRep_bRepIsCrawling();
    
public:
    UFUNCTION(BlueprintNativeEvent)
    void OnEndCrawl(float HalfHeightAdjust, float ScaledHalfHeightAdjust);
    
    UFUNCTION(BlueprintCallable)
    FHitResult MoveWithCollision(const FVector& MovementDelta, bool bTeleport);
    
    UFUNCTION(BlueprintCallable)
    FHitResult MoveToWithCollision(const FVector& MovementTarget, bool bTeleport);
    
    UFUNCTION(BlueprintPure)
    bool IsLocationUnderWater(const FVector& Location) const;
    
    UFUNCTION(BlueprintPure)
    bool IsCrawling() const;
    
    UFUNCTION(BlueprintPure)
    bool IsCameraUnderWater() const;
    
    UFUNCTION(BlueprintCallable)
    void InputTurnAtRateRight(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputTurnAtRateLeft(float Value);
    
    UFUNCTION(BlueprintCallable)
    void InputTurnAtRateAxis(float Value);
    
    UFUNCTION(BlueprintPure)
    float GetEyeHeightSpringPosition() const;
    
    UFUNCTION(BlueprintPure)
    float GetDesiredEyeHeightOffsetFromFloor() const;
    
    UFUNCTION(BlueprintPure)
    float GetDesiredEyeHeightOffset() const;
    
    UFUNCTION(BlueprintPure)
    float GetDefaultEyeHeightFromFloor(bool bIgnoreCrouch, bool bIgnoreCrawl) const;
    
    UFUNCTION(BlueprintPure)
    float GetCurrentEyeHeightOffset() const;
    
    UFUNCTION(BlueprintCallable)
    void Crawl(bool bClientSimulation);
    
    UFUNCTION(Client, Reliable)
    void ClientMimicTeleportTo(const FVector& DestLocation, const FRotator& DestRotation, bool bIsATest, bool bNoCheck);
    
    UFUNCTION(BlueprintPure)
    bool CanEverCrawl() const;
    
    UFUNCTION(BlueprintPure)
    bool CanCrawl() const;
    
    UFUNCTION(BlueprintCallable)
    void AdjustCurrentEyeHeightOffsetFromFloor(float OffsetDelta, bool bAffectSpring);
    
    UFUNCTION(BlueprintCallable)
    void AdjustCurrentEyeHeightOffset(float Offset, bool bReset);
    
};

