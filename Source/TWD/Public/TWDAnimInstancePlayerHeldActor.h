#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SDIAnimInstance.h"
#include "UObject/NoExportTypes.h"
#include "TWDDragSettings.h"
#include "TWDArmDragSettings.h"
#include "UObject/NoExportTypes.h"
#include "TWDAnimInstancePlayerHeldActor.generated.h"

class ASDIHeldActor;

UCLASS(NonTransient)
class TWD_API UTWDAnimInstancePlayerHeldActor : public USDIAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite)
    TSubclassOf<ASDIHeldActor> HeldActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName WindedCurveName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName CrouchedCurveName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bEnableDrag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FTWDDragSettings> DragSettingsN;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FTWDDragSettings> DragSettingsNWinded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FTWDDragSettings> DragSettingsCLF;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FTWDDragSettings> DragSettingsCLFWinded;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTWDDragSettings DragSettings;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevDrag;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator Drag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bEnableArmDrag;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float ArmDrag;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevArmDrag;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FTWDArmDragSettings ArmDragSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FTWDArmDragSettings> ArmDragSettingsN;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FTWDArmDragSettings> ArmDragSettingsNWinded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FTWDArmDragSettings> ArmDragSettingsCLF;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FTWDArmDragSettings> ArmDragSettingsCLFWinded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bEnableLean;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Lean;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector PrevLean;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float LeanInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, float> LeanInterpSpeedSettingsN;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, float> LeanInterpSpeedSettingsCLF;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LeanRotationVelFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bEnableAimRotationInterp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator AimRotationInterp;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float AimRotationInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, float> AimRotationInterpSpeedSettingsN;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, float> AimRotationInterpSpeedSettingsNWinded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, float> AimRotationInterpSpeedSettingsCLF;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, float> AimRotationInterpSpeedSettingsCLFWinded;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector Velocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector PrevVelocity;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float PrevLateralSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LateralSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float VerticalSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ForwardSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RightSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LateralSpeedPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ForwardSpeedPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float RightSpeedPercent;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator CharacterRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevCharacterRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator AimRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevAimRotation;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator AimRotationVel;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FRotator PrevAimRotationVel;
    
public:
    UTWDAnimInstancePlayerHeldActor();
    UFUNCTION(BlueprintCallable)
    void SetDragYawSpringConstants(float SpringStiffness, float DampeningRatio);
    
    UFUNCTION(BlueprintCallable)
    void SetDragPitchSpringConstants(float SpringStiffness, float DampeningRatio);
    
    UFUNCTION(BlueprintNativeEvent)
    void Initialize(TSubclassOf<ASDIHeldActor> ThisClass);
    
};

