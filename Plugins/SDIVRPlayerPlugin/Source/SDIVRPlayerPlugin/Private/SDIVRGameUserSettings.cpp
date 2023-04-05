#include "SDIVRGameUserSettings.h"

class USDIVRGameUserSettings;

void USDIVRGameUserSettings::SetWritePermissions(bool bSet) {
}

void USDIVRGameUserSettings::SetUseThrowingReleaseTimeOffsetQuestLink(bool Value) {
}

void USDIVRGameUserSettings::SetUserThrowingReleaseVelocityMultiplier(float Multiplier) {
}

void USDIVRGameUserSettings::SetToDefaultsControls() {
}

void USDIVRGameUserSettings::SetReadPermissions(bool bSet) {
}

void USDIVRGameUserSettings::SetMicPermissionRequestedEver(bool bSet) {
}

void USDIVRGameUserSettings::SetMicPermission(bool bSet) {
}

void USDIVRGameUserSettings::SetAppPermissionRequestedEver(bool bSet) {
}

void USDIVRGameUserSettings::RequestDeferredSaveSettings() {
}

bool USDIVRGameUserSettings::IsEnableOculusSteamVR() const {
    return false;
}

bool USDIVRGameUserSettings::GetWritePermissions() const {
    return false;
}

bool USDIVRGameUserSettings::GetUseThrowingReleaseTimeOffsetQuestLink() const {
    return false;
}

float USDIVRGameUserSettings::GetUserThrowingReleaseVelocityMultiplier() const {
    return 0.0f;
}

USDIVRGameUserSettings* USDIVRGameUserSettings::GetSDIVRGameUserSettings() {
    return NULL;
}

bool USDIVRGameUserSettings::GetReadPermissions() const {
    return false;
}

bool USDIVRGameUserSettings::GetMicPermissionRequestedEver() const {
    return false;
}

bool USDIVRGameUserSettings::GetMicPermission() const {
    return false;
}

bool USDIVRGameUserSettings::GetMicEnabled() const {
    return false;
}

bool USDIVRGameUserSettings::GetAppPermissionRequestedEver() const {
    return false;
}

USDIVRGameUserSettings::USDIVRGameUserSettings() {
    this->bDeferredSaveSettingsRequested = false;
    this->bMicEnabled = false;
    this->bMicPermissionRequestedEver = false;
    this->bMicPermission = false;
    this->bWritePermission = false;
    this->bReadPermission = false;
    this->bAppPermissionRequestedEver = false;
    this->bUseThrowingReleaseTimeOffsetQuestLink = false;
    this->UserThrowingReleaseVelocityMultiplier = 0.00f;
}

