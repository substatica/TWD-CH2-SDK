#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SDIExportInterface.h"
#include "SDIExportData.h"
#include "SDIDamageData.h"
#include "RFloatExp.h"
#include "UObject/NoExportTypes.h"
#include "SDICoreDOTComponent.generated.h"

class AController;
class USDICoreDOTComponent;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDICOREPLUGIN_API USDICoreDOTComponent : public UActorComponent, public ISDIExportInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    FSDIExportData ExportData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIDamageData Damage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloatExp Delay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloatExp Duration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRFloatExp Interval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bAffectedByTimeDilation;
    
    UPROPERTY(Transient)
    float IntervalTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_RepTotalDuration)
    float RepTotalDuration;
    
    UPROPERTY(BlueprintReadWrite, Replicated, Transient)
    float RepDurationTimer;
    
    UPROPERTY(Transient)
    float DelayTimer;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    float AttachedTime;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    AController* EventInstigator;
    
    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing=OnRep_RepDamageCauser)
    AActor* RepDamageCauser;
    
public:
    USDICoreDOTComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    static int32 RemoveDOT(TSubclassOf<USDICoreDOTComponent> DOTClass, AActor* Target, AController* inEventInstigator, AActor* inDamageCauser);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ReApplyWith(const USDICoreDOTComponent* BaseDOT, AActor* Target, AController* inEventInstigator, AActor* inDamageCauser, const TMap<FName, float>& CustomData);
    
    UFUNCTION(BlueprintNativeEvent)
    void ProcessCustomData(bool bIsReApply, AActor* Target, AController* inEventInstigator, AActor* inDamageCauser, const TMap<FName, float>& CustomData);
    
    UFUNCTION()
    void OnRep_RepTotalDuration(float OldRepTotalDuration);
    
    UFUNCTION()
    void OnRep_RepDamageCauser(AActor* OldRepDamageCauser);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnDurationUpdated(float OldRepTotalDuration, float NewRepTotalDuration);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnDamageCauserUpdated(AActor* OldRepDamageCauser, AActor* NewRepDamageCauser);
    
public:
    UFUNCTION(BlueprintPure)
    bool HasAuthority() const;
    
    UFUNCTION(BlueprintPure)
    float GetTimeLeft() const;
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    bool CanApplyTo(AActor* Target, AController* inEventInstigator, AActor* inDamageCauser, const TMap<FName, float>& CustomData) const;
    
    UFUNCTION(BlueprintCallable)
    static USDICoreDOTComponent* ApplyDOT(TSubclassOf<USDICoreDOTComponent> DOTClass, AActor* Target, AController* inEventInstigator, AActor* inDamageCauser, const TMap<FName, float>& CustomData);
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    bool AddCheckExistingDOT(USDICoreDOTComponent* DOTComp, AActor* Target, AController* inEventInstigator, AActor* inDamageCauser, const TMap<FName, float>& CustomData) const;
    
    
    // Fix for true pure virtual functions not being implemented
public:
    UFUNCTION(BlueprintCallable)
    FGuid K2GetExportGuid() const override PURE_VIRTUAL(K2GetExportGuid, return FGuid{};);
    
    UFUNCTION(BlueprintCallable)
    FText GetExportText(FName Key) const override PURE_VIRTUAL(GetExportText, return FText::GetEmpty(););
    
    UFUNCTION(BlueprintCallable)
    FText GetExportDisplayName() const override PURE_VIRTUAL(GetExportDisplayName, return FText::GetEmpty(););
    
    UFUNCTION(BlueprintCallable)
    FText GetExportDescription() const override PURE_VIRTUAL(GetExportDescription, return FText::GetEmpty(););
    
    UFUNCTION(BlueprintCallable)
    bool FindExportText(FName Key, FText& OutText) const override PURE_VIRTUAL(FindExportText, return false;);
    
};

