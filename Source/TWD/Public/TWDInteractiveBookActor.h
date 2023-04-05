#pragma once
#include "CoreMinimal.h"
#include "TWDProp.h"
#include "TWDInteractiveBookActor.generated.h"

class UMaterialInterface;
class UCapsuleComponent;
class UArrowComponent;
class UHapticFeedbackEffect_Base;
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
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UMaterialInterface* PageMaterial;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    UHapticFeedbackEffect_Base* EdgeTouchHaptic;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float LookConeAngle;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    float OpenLookConeAngleDelta;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USkeletalMeshComponent* BookMesh;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UArrowComponent* Arrow;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* SpineRoot;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UTWDWidgetComponent* LeftPageWidget;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UTWDWidgetComponent* RightPageWidget;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UCapsuleComponent* Capsule;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* PointGripLeft;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* PointGripRight;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* RightPageRoot;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USceneComponent* LeftPageRoot;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ASDIPlayerHand* GrabHand;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    bool bBookOpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* PageFlipSound;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    bool bInteractPressed;
    
public:
    ATWDInteractiveBookActor();
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

