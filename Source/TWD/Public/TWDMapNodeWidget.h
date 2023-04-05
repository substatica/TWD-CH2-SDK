#pragma once
#include "CoreMinimal.h"
#include "TWDUserWidget.h"
#include "EMapTerritoryNodeStatus.h"
#include "TWDMapNodeWidget.generated.h"

class UMaterialInterface;
class UImage;
class UTextBlock;
class UTexture2D;
class UMaterialInstanceDynamic;

UCLASS(EditInlineNew)
class TWD_API UTWDMapNodeWidget : public UTWDUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly)
    bool SetupCompleted;
    
protected:
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FName NodeIconParam;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FName NodeLockedParam;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FName NodeExploredParam;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    FName NodeDisabledParam;
    
private:
    UPROPERTY(Instanced, Transient)
    UImage* NodeIconImage;
    
    UPROPERTY(Instanced, Transient)
    UTextBlock* NodeTitleBox;
    
    UPROPERTY(Transient)
    UMaterialInstanceDynamic* NodeMID;
    
    UPROPERTY(Instanced, Transient)
    TArray<UImage*> AttributeImages;
    
public:
    UTWDMapNodeWidget();
    UFUNCTION(BlueprintCallable)
    void UpdateExplorationStatus(EMapTerritoryNodeStatus ExplorationStatus);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetReferences_BP();
    
    UFUNCTION(BlueprintCallable)
    void SetReferences(UImage* NodeIcon, UTextBlock* NodeTitle, UMaterialInstanceDynamic* NodeImageMID, bool bForceReset);
    
    UFUNCTION(BlueprintCallable)
    void SetNodeData(int32 MapNodeIndex, UTexture2D* NodeIconTexture, FText NodeTitle, TArray<UMaterialInterface*> AttributeIconMIs);
    
};

