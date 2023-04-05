#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SDIMeleeWeaponStabParams.h"
#include "ESDIMeleeWeaponStabState.h"
#include "SDIMeleeWeaponStabInterface.generated.h"

class UCurveFloat;
class ASDIMeleeWeaponActor;
class UPrimitiveComponent;
class ASDICharacter;
class AActor;

UINTERFACE(Blueprintable)
class SDIVRPLAYERPLUGIN_API USDIMeleeWeaponStabInterface : public UInterface {
    GENERATED_BODY()
};

class SDIVRPLAYERPLUGIN_API ISDIMeleeWeaponStabInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent)
    void RemoveStuckWeapon(ASDIMeleeWeaponActor* Weapon);
    
    UFUNCTION(BlueprintNativeEvent)
    void RemoveStabWeapon(ASDIMeleeWeaponActor* Weapon);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStabStart(const FSDIMeleeWeaponStabParams& StabParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStabEnd(bool bRemovedWeapon, const FSDIMeleeWeaponStabParams& StabParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStabContact(const FSDIMeleeWeaponStabParams& StabParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void OnStabComplete(const FSDIMeleeWeaponStabParams& StabParams);
    
    UFUNCTION(BlueprintNativeEvent)
    bool IsStabPossible(const UPrimitiveComponent* StabComp, const FName& BoneName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsBeingStabbed(ASDICharacter*& OutCharacter, ASDIMeleeWeaponActor*& OutWeapon, ESDIMeleeWeaponStabState& OutState) const;
    
    UFUNCTION(BlueprintNativeEvent)
    UCurveFloat* GetStabPullCurve(const FSDIMeleeWeaponStabParams& StabParams) const;
    
    UFUNCTION(BlueprintNativeEvent)
    UCurveFloat* GetStabCurve(const FSDIMeleeWeaponStabParams& StabParams) const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool CheckStab(const FSDIMeleeWeaponStabParams& StabParams) const;
    
    UFUNCTION(BlueprintNativeEvent)
    void AllowStabMoveSync(AActor* Attacker, const FSDIMeleeWeaponStabParams& StabParams, bool& bOutMoveAttacker, bool& bOutMoveSelf) const;
    
    UFUNCTION(BlueprintNativeEvent)
    bool AddStuckWeapon(const FSDIMeleeWeaponStabParams& StabParams);
    
    UFUNCTION(BlueprintNativeEvent)
    void AddStabWeapon(const FSDIMeleeWeaponStabParams& StabParams);
    
};

