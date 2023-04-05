#pragma once
#include "CoreMinimal.h"
#include "ETWDSavedNoteCategory.generated.h"

UENUM(BlueprintType)
enum class ETWDSavedNoteCategory : uint8 {
    Misc,
    CaseyQuestline,
    MayQuestline,
    Sidequest,
    AmbreDrawing,
    Tutorial,
    TowerIntel,
    SafeCode,
    ReserveRemnants,
    AxemanQuestline,
    SableQuestline,
    MamaQuestline,
    ExileQuests,
    PawnKing,
    FatherCarter,
    Recipe,
    Postcard,
    END,
    BEGIN = 0x0,
    ETWDSavedNoteCategory_MAX = 0x12,
};

