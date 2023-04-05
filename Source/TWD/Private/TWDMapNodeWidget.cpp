#include "TWDMapNodeWidget.h"

class UImage;
class UTextBlock;
class UTexture2D;
class UMaterialInstanceDynamic;
class UMaterialInterface;

void UTWDMapNodeWidget::UpdateExplorationStatus(EMapTerritoryNodeStatus ExplorationStatus) {
}


void UTWDMapNodeWidget::SetReferences(UImage* NodeIcon, UTextBlock* NodeTitle, UMaterialInstanceDynamic* NodeImageMID, bool bForceReset) {
}

void UTWDMapNodeWidget::SetNodeData(int32 MapNodeIndex, UTexture2D* NodeIconTexture, FText NodeTitle, TArray<UMaterialInterface*> AttributeIconMIs) {
}

UTWDMapNodeWidget::UTWDMapNodeWidget() {
    this->SetupCompleted = false;
    this->NodeIconImage = NULL;
    this->NodeTitleBox = NULL;
    this->NodeMID = NULL;
}

