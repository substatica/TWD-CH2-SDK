#include "SDISaveExportResponse.h"

FSDISaveExportResponse::FSDISaveExportResponse() {
    this->ErrorCategory = ESDIServiceErrorCategory::OK;
    this->ErrorCode = ESaveExportErrorCode::NotInitialized;
    this->HttpResponseCode = 0;
}

