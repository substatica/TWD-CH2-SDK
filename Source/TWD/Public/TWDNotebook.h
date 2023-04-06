#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ESDIInteractRangeType.h"
#include "TWDInteractiveBookActor.h"
#include "ETWDNotebookSectionIndex.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ESDIInteractiveInteractType.h"
#include "SavedLookatNotebookData.h"
#include "ETWDSavedNoteCategory.h"
#include "TWDNotebook.generated.h"

class UBoxComponent;
class ASDIInventoryActor;
class USceneComponent;
class UPrimitiveComponent;
class UTWDNonVRNotebookWidget;
class ASDIPlayerHand;
class UTWDTask;

UCLASS()
class TWD_API ATWDNotebook : public ATWDInteractiveBookActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    ETWDNotebookSectionIndex CurrentSectionIndex;
    
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* LeftTabsRoot;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* TabTasksCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* TabTrackingCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* TabCharacterCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* TabMapCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USceneComponent* RightTabsRoot;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* TabNotesCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* TabOrdersCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* TabStoryCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UBoxComponent* TabExtraCollision;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    TArray<UPrimitiveComponent*> TabCollisions;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    TArray<UPrimitiveComponent*> FavorEnabledTabCollisions;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<UTWDNonVRNotebookWidget> NonVRNotebookWidgetClass;
    
    UPROPERTY(BlueprintReadWrite)
    bool bNonVRInputActive;
    
private:
    UPROPERTY(Transient)
    bool bInsideOnRep_bRepInsideInventory;
    
    UPROPERTY(Transient)
    TMap<UPrimitiveComponent*, bool> PreviousVisibility;
    
    UPROPERTY(Transient)
    TMap<UPrimitiveComponent*, TEnumAsByte<ECollisionEnabled::Type>> PreviousCollision;
    
    UPROPERTY(Instanced, Transient)
    UTWDNonVRNotebookWidget* NonVRNotebookWidget;
    
public:
    ATWDNotebook(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StopNonVRInteraction();
    
    UFUNCTION(BlueprintCallable)
    void StartNonVRInteraction();
    
    UFUNCTION(BlueprintCallable)
    ASDIInventoryActor* SpawnNoteActor(TSubclassOf<ASDIInventoryActor> NoteClass, FTransform SpawnLocation);
    
    UFUNCTION(BlueprintPure)
    bool ShouldGrabSavedNoteInsteadOfInteract(ESDIInteractiveInteractType Type, ASDIPlayerHand* hand, ESDIInteractRangeType RangeType, UPrimitiveComponent* Component) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSetupSection();
    
protected:
    UFUNCTION(BlueprintPure)
    bool IsTabCollision(UPrimitiveComponent* Component) const;
    
    UFUNCTION()
    void InputNonVRPageRight();
    
    UFUNCTION()
    void InputNonVRPageLeft();
    
public:
    UFUNCTION(BlueprintPure)
    TArray<UTWDTask*> GetTasksSorted() const;
    
    UFUNCTION(BlueprintPure)
    TArray<UTWDTask*> GetTasks() const;
    
    UFUNCTION(BlueprintPure)
    TArray<FSavedLookatNotebookData> GetNotesSorted(ETWDSavedNoteCategory Category) const;
    
    UFUNCTION(BlueprintPure)
    TArray<FSavedLookatNotebookData> GetNotes(ETWDSavedNoteCategory Category) const;
    
    UFUNCTION(BlueprintPure)
    TArray<ASDIInventoryActor*> GetInventory() const;
    
    UFUNCTION(BlueprintCallable)
    void FlipToSection(ETWDNotebookSectionIndex Section);
    
    UFUNCTION(BlueprintCallable)
    void FlipToPrevSection();
    
    UFUNCTION(BlueprintCallable)
    void FlipToNextSection();
    
    UFUNCTION(BlueprintCallable)
    void ActivateNonVRInteraction();
    
};

