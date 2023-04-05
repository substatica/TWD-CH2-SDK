#include "TWDSaveExportNode.h"

class UObject;
class UTWDSaveExportNode;

void UTWDSaveExportNode::ResponseReceived(FTWDExportResponse Response) {
}

UTWDSaveExportNode* UTWDSaveExportNode::RequestExportSaveAtIndex(const UObject* WorldContextObject, int32 ProfileIndex, int32 SaveIndex) {
    return NULL;
}

UTWDSaveExportNode* UTWDSaveExportNode::RequestExportLegacySave(const UObject* WorldContextObject) {
    return NULL;
}

UTWDSaveExportNode::UTWDSaveExportNode() {
}

