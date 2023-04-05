#include "TWDSaveImporter.h"

void UTWDSaveImporter::OnImportResponseReceived(FSDISaveImportResponse Response) {
}

bool UTWDSaveImporter::ImportLegacySaveFromCode(const FString& RequestCode) {
    return false;
}

EImportSaveGameResult UTWDSaveImporter::GetStatus() const {
    return EImportSaveGameResult::OK;
}

UTWDSaveImporter::UTWDSaveImporter() {
    this->LegacySave = NULL;
}

