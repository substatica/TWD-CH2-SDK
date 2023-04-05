#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "ESDIVRControllerType.h"
#include "UObject/NoExportTypes.h"
#include "TWDMenuHand.generated.h"

class UMotionControllerComponent;
class USkeletalMeshComponent;
class UWidgetInteractionComponent;
class UStaticMeshComponent;
class USceneComponent;

UCLASS()
class TWD_API ATWDMenuHand : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UMotionControllerComponent* MotionControllerComponent;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* HandMeshComponent;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UStaticMeshComponent* MenuPointerComponent;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UWidgetInteractionComponent* WidgetInteractionComponent;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* HitIndicatorComponent;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FString ClickInputName;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FString NonVRClickInputName;
    
    UPROPERTY(BlueprintReadOnly, Transient)
    bool bClicking;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<ESDIVRControllerType, FVector> MenuPointerOffset;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<ESDIVRControllerType, FRotator> PointerRelativeRotation;
    
public:
    ATWDMenuHand();
};

