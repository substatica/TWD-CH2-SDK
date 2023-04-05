#include "SDISaveExportSubsystem.h"

class UObject;

bool USDISaveExportSubsystem::K2ExportObject(const UObject* ObjPayload, FSDIJsonExportSettings Settings) {
    return false;
}

bool USDISaveExportSubsystem::ExportString(const FString& SerializedString) {
    return false;
}

USDISaveExportSubsystem::USDISaveExportSubsystem() {
}

