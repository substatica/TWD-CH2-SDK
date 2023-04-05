#include "TWDExportResponse.h"

FTWDExportResponse::FTWDExportResponse() {
    this->TWDExportErrorCode = EExportSaveGameResult::OK;
    this->ErrorCategory = ESDIServiceErrorCategory::OK;
    this->HttpResponseCode = 0;
}

