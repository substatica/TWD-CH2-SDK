#pragma once
#include "CoreMinimal.h"
#include "SDIWeaponHitCapsuleComponent.h"
#include "ESDIAxis.h"
#include "Curves/CurveFloat.h"
#include "TWDWeaponBoneStabCurveOverrideMapEntry.h"
#include "SDIDamageData.h"
#include "TWDWeaponStabSettings.h"
#include "SDIPlayerHandMove.h"
#include "ETWDCharacterHitRegion.h"
#include "TWDWeaponDismemberSettings.h"
#include "TWDWeaponStickSettings.h"
#include "ETWDNonVRMeleeAttackType.h"
#include "TWDWeaponHitCapsuleComponent.generated.h"

class UPhysicalMaterial;

UCLASS(EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UTWDWeaponHitCapsuleComponent : public USDIWeaponHitCapsuleComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowStab;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis StabAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis ThrownStabAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis LaunchedStabAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis StabWoundAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabCollisionCorrectionStep;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabStartDepth;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabMaxDepth;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabMaintainMinStartDepth;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabExtractionDepth;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StabInitialDepthVelocityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StabThrownInitialDepthVelocityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StabLaunchedInitialDepthVelocityCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabInitialDepthVelocityRemovePawnVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabStartLerpTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabThrownStartLerpTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabLaunchedStartLerpTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabCanPush;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bUseStabPushTriggerDepth;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float StabPushTriggerDepth;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabCanDrag;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabFromThrown;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabFromLaunched;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabUsePullOutMove;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabStickAfterRelease;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabBrainingUseRagdoll;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bStabRefineHitInfo;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StabCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FName, FTWDWeaponBoneStabCurveOverrideMapEntry> BoneStabCurveOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FRuntimeFloatCurve StabPullCurve;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<FName, FTWDWeaponBoneStabCurveOverrideMapEntry> BoneStabPullCurveOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIDamageData StabStartDamageData;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIDamageData StabCompleteDamageData;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIDamageData StabPullDamageData;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    int32 StabSawIncrements;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIPlayerHandMove StabDragPullOutMove;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIPlayerHandMove StabPullOutMove;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<ETWDCharacterHitRegion, FTWDWeaponStabSettings> StabSettings;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDismemberUsePullOutMove;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    FSDIPlayerHandMove DismemberPullOutMove;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowDismember;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis DismemberAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bUseDismemberLateralAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis DismemberLateralAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis DismemberFlatAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<ETWDCharacterHitRegion, FTWDWeaponDismemberSettings> DismemberSettings;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bAllowStick;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis StickAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis ThrownStickAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis LaunchedStickAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TMap<UPhysicalMaterial*, FTWDWeaponStickSettings> StickSettings;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIAxis WoundAxis;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSet<ETWDNonVRMeleeAttackType> NonVRAttackTypeFilter;
    
    UPROPERTY(EditDefaultsOnly)
    bool bCapsuleAndWeaponMustAgreeOnShouldHandleHits;
    
public:
    UTWDWeaponHitCapsuleComponent();
    UFUNCTION(BlueprintCallable)
    void SetStickingAllowed(bool bCanDismember);
    
    UFUNCTION(BlueprintCallable)
    void SetStabbingAllowed(bool bCanStab);
    
    UFUNCTION(BlueprintCallable)
    void SetDismemberAllowed(bool bCanDismember);
    
    UFUNCTION(BlueprintPure)
    bool IsStickingAllowed() const;
    
    UFUNCTION(BlueprintPure)
    bool IsStabbingAllowed() const;
    
    UFUNCTION(BlueprintPure)
    bool IsDismemberAllowed() const;
    
};

