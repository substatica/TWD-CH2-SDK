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
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UMotionControllerComponent* MotionControllerComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* HandMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UStaticMeshComponent* MenuPointerComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UWidgetInteractionComponent* WidgetInteractionComponent;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* HitIndicatorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString ClickInputName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString NonVRClickInputName;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    bool bClicking;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<ESDIVRControllerType, FVector> MenuPointerOffset;
    
    UPROPERTY(EditDefaultsOnly)
    TMap<ESDIVRControllerType, FRotator> PointerRelativeRotation;
    
public:
    ATWDMenuHand(const FObjectInitializer& ObjectInitializer);
};

