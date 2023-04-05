#include "TWDSaveExporter.h"

class UTWDSaveGame;

void UTWDSaveExporter::HandleResponse(FSDISaveExportResponse Response) {
}

bool UTWDSaveExporter::ExportSaveAtIndex(int32 ProfileIndex, int32 SaveIndex) {
    return false;
}

bool UTWDSaveExporter::ExportSave(const UTWDSaveGame* SaveGame) {
    return false;
}

bool UTWDSaveExporter::ExportMarketingCode(TArray<FString> Flags) {
    return false;
}

UTWDSaveExporter::UTWDSaveExporter() {
}

