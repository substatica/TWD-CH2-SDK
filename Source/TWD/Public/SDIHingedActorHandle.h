#pragma once
#include "CoreMinimal.h"
#include "TWDInteractiveActor.h"
#include "EHandleType.h"
#include "UObject/NoExportTypes.h"
#include "SDIGripInfo.h"
#include "SDIHingedActorHandle.generated.h"

class UArrowComponent;
class UPrimitiveComponent;
class ASDIPlayerHand;
class UActorComponent;
class ASDISlidingInteractiveActor;
class ASDIHingedInteractiveActor;
class AActor;

UCLASS()
class TWD_API ASDIHingedActorHandle : public ATWDInteractiveActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Instanced)
    UPrimitiveComponent* GrippedComponent;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Instanced)
    UArrowComponent* RotationDetectionArrow;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ASDIPlayerHand* PlayerHand;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EHandleType HandleType;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditDefaultsOnly)
    float RotationToOpen;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditDefaultsOnly)
    float RotationAllowedIfUnlocked;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditDefaultsOnly)
    float RotationAllowedIfLocked;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere)
    float ArmLengthReleaseFactor;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere)
    float ArmLengthReleaseFactorTime;
    
    UPROPERTY(Instanced, Transient)
    TArray<UActorComponent*> GripPoints;
    
    UPROPERTY(Transient)
    TArray<FVector> GripPointInitialWorldLocations;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bForceHideHighlight;
    
    UPROPERTY(Instanced, Transient)
    UActorComponent* CurrentGrippedComponent;
    
    UPROPERTY(Transient)
    FSDIGripInfo CurrentGrippedInfo;
    
    ASDIHingedActorHandle(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetDoorLocked(bool bNewLock);
    
    UFUNCTION(BlueprintCallable)
    bool IsDoorLocked();
    
    UFUNCTION(BlueprintCallable)
    bool IsDoorClosed();
    
    UFUNCTION(BlueprintCallable)
    ASDISlidingInteractiveActor* GetSlidingActor();
    
    UFUNCTION(BlueprintCallable)
    ASDIHingedInteractiveActor* GetHingedActor();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetDoor();
    
};

