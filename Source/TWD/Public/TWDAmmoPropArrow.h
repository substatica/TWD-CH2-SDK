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
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDWeaponHitCapsuleComponent* ArrowHitCapsule;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDISplineGripComponent* ShaftGripLeft;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDISplineGripComponent* ShaftGripRight;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDISplineGripComponent* ShaftGripLeftFlip;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDISplineGripComponent* ShaftGripRightFlip;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float NockedStabMinTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float LaunchedMaxDuration;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float LaunchedMinVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float MaxMergeDurabilityDelta;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ATWDWeaponBowV2> NockedBow;
    
    UPROPERTY(BlueprintReadWrite, Transient)
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

