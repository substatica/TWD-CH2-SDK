#include "TWDSaveImportNode.h"

class UTWDSaveImportNode;
class UObject;

void UTWDSaveImportNode::ResponseReceived(FSaveImporterResult Response) {
}

UTWDSaveImportNode* UTWDSaveImportNode::RequestImportSaveUsingCode(const UObject* WorldContextObject, const FString& RequestCode) {
    return NULL;
}

UTWDSaveImportNode::UTWDSaveImportNode() {
}

