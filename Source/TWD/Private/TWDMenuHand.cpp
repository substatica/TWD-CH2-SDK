#include "TWDMenuHand.h"
#include "MotionControllerComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

ATWDMenuHand::ATWDMenuHand(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MotionControllerComponent = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionControllerComponent"));
    this->HandMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HandMeshComponent"));
    this->MenuPointerComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MenuPointerComponent"));
    this->WidgetInteractionComponent = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteractionComponent"));
    this->HitIndicatorComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HitIndicatorComponent"));
    this->bClicking = false;
}

