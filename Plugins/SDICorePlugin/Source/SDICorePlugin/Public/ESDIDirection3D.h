#pragma once
#include "CoreMinimal.h"
#include "ESDIDirection3D.generated.h"

UENUM()
enum class ESDIDirection3D : uint8 {
    None,
    Forward,
    Backward,
    Left,
    Right,
    Up,
    Down,
    ForwardLeft,
    ForwardRight,
    BackwardLeft,
    BackwardRight,
    ForwardUp,
    ForwardDown,
    BackwardUp,
    BackwardDown,
    LeftUp,
    RightUp,
    LeftDown,
    RightDown,
    ForwardLeftUp,
    ForwardRightUp,
    BackwardLeftUp,
    BackwardRightUp,
    ForwardLeftDown,
    ForwardRightDown,
    BackwardLeftDown,
    BackwardRightDown,
};

