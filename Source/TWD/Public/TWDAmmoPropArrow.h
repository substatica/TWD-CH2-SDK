#pragma once
#include "CoreMinimal.h"
#include "TWDAmmoProp.h"
#include "UObject/NoExportTypes.h"
#include "TWDAmmoPropArrow.generated.h"

class UTWDWeaponHitCapsuleComponent;
class USDISplineGripComponent;
class ATWDWeaponBowV2;

UCLASS()
class TWD_API ATWDAmmoPropArrow : public ATWDAmmoProp {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UTWDWeaponHitCapsuleComponent* ArrowHitCapsule;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDISplineGripComponent* ShaftGripLeft;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDISplineGripComponent* ShaftGripRight;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDISplineGripComponent* ShaftGripLeftFlip;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDISplineGripComponent* ShaftGripRightFlip;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float NockedStabMinTime;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float LaunchedMaxDuration;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float LaunchedMinVelocity;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float MaxMergeDurabilityDelta;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ATWDWeaponBowV2> NockedBow;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    TWeakObjectPtr<ATWDWeaponBowV2> LaunchedBow;
    
    UPROPERTY(Transient)
    float LaunchedTimestamp;
    
public:
    ATWDAmmoPropArrow(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintNativeEvent)
    void SetNockedBow(ATWDWeaponBowV2* Bow);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnArrowLaunched(const FVector& LaunchVelocity);
    
    UFUNCTION(BlueprintNativeEvent)
    void Launch(ATWDWeaponBowV2* Bow, const FVector& LaunchVelocity);
    
    UFUNCTION(BlueprintPure)
    ATWDWeaponBowV2* GetNockedBow() const;
    
};

