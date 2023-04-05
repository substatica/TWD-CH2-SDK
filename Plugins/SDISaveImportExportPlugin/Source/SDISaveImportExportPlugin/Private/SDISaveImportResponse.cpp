#include "SDISaveImportResponse.h"

FSDISaveImportResponse::FSDISaveImportResponse() {
    this->ErrorCategory = ESDIServiceErrorCategory::OK;
    this->ErrorCode = ESaveImportErrorCode::NotInitialized;
    this->HttpResponseCode = 0;
}

