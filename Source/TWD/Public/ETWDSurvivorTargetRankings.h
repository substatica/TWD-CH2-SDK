#pragma once
#include "CoreMinimal.h"
#include "ETWDSurvivorTargetRankings.generated.h"

UENUM()
enum class ETWDSurvivorTargetRankings : uint8 {
    Suspicious,
    FoundTargetNoThreatAge,
    RecentSound,
    FoundTargetNoThreat,
    Hunting,
    FoundTargetThreatAging,
    FoundTargetFarWalker,
    FoundTargetNotAging,
    LastAttacker,
};

