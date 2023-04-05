#include "SaveImporterResult.h"

FSaveImporterResult::FSaveImporterResult() {
    this->TWDImportErrorCode = EImportSaveGameResult::OK;
    this->ErrorCategory = ESDIServiceErrorCategory::OK;
    this->SDIImportErrorCode = ESaveImportErrorCode::NotInitialized;
    this->HttpResponseCode = 0;
    this->bShippingCheatsEnabled = false;
}

