#pragma once
#include "CoreMinimal.h"
#include "TWDProp.h"
#include "TWDInteractiveBookActor.generated.h"

class UMaterialInterface;
class UCapsuleComponent;
class UArrowComponent;
class UObject;
class USkeletalMeshComponent;
class USceneComponent;
class UTWDWidgetComponent;
class USDIPointGripComponent;
class ASDIPlayerHand;
class UAkAudioEvent;
class UUserWidget;

UCLASS()
class TWD_API ATWDInteractiveBookActor : public ATWDProp {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UMaterialInterface* PageMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    UObject* EdgeTouchHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float LookConeAngle;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float OpenLookConeAngleDelta;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* BookMesh;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UArrowComponent* Arrow;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* SpineRoot;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDWidgetComponent* LeftPageWidget;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UTWDWidgetComponent* RightPageWidget;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UCapsuleComponent* Capsule;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* PointGripLeft;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* PointGripRight;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* RightPageRoot;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* LeftPageRoot;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ASDIPlayerHand* GrabHand;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    bool bBookOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* PageFlipSound;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    bool bInteractPressed;
    
public:
    ATWDInteractiveBookActor(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateBookOpen();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateBookClosed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPopulatePage(int32 PageIndex, UUserWidget* PageWidget);
    
public:
    UFUNCTION(BlueprintPure)
    USkeletalMeshComponent* GetBookMesh() const;
    
    UFUNCTION(BlueprintCallable)
    void CommitPages();
    
};

