#include "NetworkManagerGameMode.h"

ANetworkManagerGameMode::ANetworkManagerGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bSDICallbackSucceeded = false;
    this->PendingGameServerUpdate = false;
    this->PendingGameServerStatus = 1;
    this->PendingGameServerPort = -1;
    this->bIsRunningOnAWS = false;
}

