#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SDIAsyncOverlapGeneratorComponentEndOverlapSignatureDelegate.h"
#include "SDIAsyncOverlapGeneratorComponentBeginOverlapSignatureDelegate.h"
#include "SDIAsyncOverlapGeneratorComponentActorBeginOverlapSignatureDelegate.h"
#include "SDIAsyncOverlapGeneratorComponentActorEndOverlapSignatureDelegate.h"
#include "SDIAsyncOverlapEventGeneratorComponent.generated.h"

class UPrimitiveComponent;
class AActor;
class USDIAsyncOverlapEventGeneratorComponent;

UCLASS(BlueprintType, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SDICOREPLUGIN_API USDIAsyncOverlapEventGeneratorComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Instanced, Transient)
    UPrimitiveComponent* PrimitiveComponent;
    
    UPROPERTY(Instanced, Transient)
    TArray<UPrimitiveComponent*> OverlappedComponents;
    
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<AActor>> OverlappedActors;
    
    UPROPERTY(Transient)
    bool bDynamicallyCreated;
    
    UPROPERTY(Transient)
    bool bIsUpdatingOverlaps;
    
    UPROPERTY(Transient)
    bool bClearOverlapsRequested;
    
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<AActor>> PendingActorsDestroyed;
    
    UPROPERTY(Transient)
    bool bAsyncOverlapHandlePending;
    
    UPROPERTY(EditAnywhere)
    TMap<TSoftClassPtr<AActor>, bool> ActorClassOverlapFilter;
    
    UPROPERTY(EditAnywhere)
    bool bCanOverlapOwner;
    
    UPROPERTY(EditAnywhere)
    bool bRouteActorOverlapsToOwner;
    
    UPROPERTY(EditAnywhere)
    bool bReciprocateComponentOverlapDelegates;
    
    UPROPERTY(EditAnywhere)
    bool bReciprocateActorOverlapDelegates;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDIAsyncOverlapGeneratorComponentBeginOverlapSignature OnComponentBeginOverlap;
    
    UPROPERTY(BlueprintAssignable)
    FSDIAsyncOverlapGeneratorComponentEndOverlapSignature OnComponentEndOverlap;
    
    UPROPERTY(BlueprintAssignable)
    FSDIAsyncOverlapGeneratorComponentActorBeginOverlapSignature OnActorBeginOverlap;
    
    UPROPERTY(BlueprintAssignable)
    FSDIAsyncOverlapGeneratorComponentActorEndOverlapSignature OnActorEndOverlap;
    
    USDIAsyncOverlapEventGeneratorComponent();
    UFUNCTION(BlueprintCallable)
    void SetRouteActorOverlapsToOwner(bool bRouteToOwner);
    
    UFUNCTION(BlueprintCallable)
    void SetReciprocateOverlapDelegates(bool bReciprocateComponents, bool bReciprocateActors);
    
    UFUNCTION(BlueprintCallable)
    void SetComponent(UPrimitiveComponent* InComp);
    
    UFUNCTION(BlueprintCallable)
    void SetCanOverlapOwner(bool bOverlapOwner);
    
    UFUNCTION(BlueprintCallable)
    void RemoveActorClassOverlapFilter(TSoftClassPtr<AActor> ActorClass);
    
protected:
    UFUNCTION()
    void OnComponentCollisionSettingsChanged(UPrimitiveComponent* ChangedComponent);
    
    UFUNCTION()
    void OnActorDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsOverlappingComponent(const UPrimitiveComponent* OtherComp) const;
    
    UFUNCTION(BlueprintPure)
    bool IsOverlappingActor(const AActor* Other) const;
    
    UFUNCTION(BlueprintPure)
    UPrimitiveComponent* GetComponent() const;
    
    UFUNCTION(BlueprintCallable)
    static USDIAsyncOverlapEventGeneratorComponent* GetAsyncOverlapEventGeneratorComponentFor(UPrimitiveComponent* Component, bool bCreate);
    
    UFUNCTION(BlueprintCallable)
    void ClearActorClassOverlapFilter();
    
    UFUNCTION(BlueprintCallable)
    void AddActorClassOverlapFilter(TSoftClassPtr<AActor> ActorClass, bool bAllowOverlap);
    
};

