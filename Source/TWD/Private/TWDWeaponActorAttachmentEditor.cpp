#include "TWDWeaponActorAttachmentEditor.h"
#include "Components/SceneComponent.h"

ATWDWeaponActorAttachmentEditor::ATWDWeaponActorAttachmentEditor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WeaponAttach = CreateDefaultSubobject<USceneComponent>(TEXT("WeaponAttach"));
    this->WeaponActorClass = NULL;
    this->MaxWeaponDistance = 256.00f;
    this->WeaponActor = NULL;
}

