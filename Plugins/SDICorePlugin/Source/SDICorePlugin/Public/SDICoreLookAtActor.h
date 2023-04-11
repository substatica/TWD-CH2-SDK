#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "SDIAkAudioEventPairDynamicLoop.h"
#include "SDICoreLookAtActorDisengagedSignatureDelegate.h"
#include "SDICoreLookAtActorEngagedSignatureDelegate.h"
#include "Engine/EngineTypes.h"
#include "SDICoreLookAtActor.generated.h"

class ACharacter;
class USphereComponent;
class UAkComponent;
class UPrimitiveComponent;

UCLASS()
class SDICOREPLUGIN_API ASDICoreLookAtActor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USphereComponent* SphereCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UAkComponent* AkAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FSDIAkAudioEventPairDynamicLoop AudioEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float EngageAngleDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DisengageAngleDegrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float MinEngagedTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float ReEngageDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bReEngageRequiresDisengage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TEnumAsByte<ECollisionChannel> LosChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float LosRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bStartActive;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ACharacter> LookAtCharacter;
    
    UPROPERTY(Transient)
    float EngagedTimestamp;
    
    UPROPERTY(Transient)
    float ReEngageTimestamp;
    
public:
    UPROPERTY(BlueprintAssignable)
    FSDICoreLookAtActorEngagedSignature OnLookAtActorEngagedDelegate;
    
    UPROPERTY(BlueprintAssignable)
    FSDICoreLookAtActorDisengagedSignature OnLookAtActorDisengagedDelegate;
    
    ASDICoreLookAtActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetActive(bool bActive);
    
    UFUNCTION()
    void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintPure)
    bool IsEngaged(ACharacter*& OutCharacter, float& OutTime) const;
    
    UFUNCTION(BlueprintPure)
    bool IsActive() const;
    
    UFUNCTION(BlueprintNativeEvent)
    void EngageLookAt(ACharacter* LookAtChar);
    
    UFUNCTION(BlueprintNativeEvent)
    void DisengageLookAt(ACharacter* LookAtChar);
    
};

