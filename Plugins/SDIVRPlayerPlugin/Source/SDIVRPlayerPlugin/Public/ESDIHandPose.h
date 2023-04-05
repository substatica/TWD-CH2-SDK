#pragma once
#include "CoreMinimal.h"
#include "ESDIHandPose.generated.h"

UENUM(BlueprintType)
enum class ESDIHandPose : uint8 {
    HP_Base,
    HP_Fist = 0x0,
    HP_Cylinder,
    HP_Sphere,
    HP_Cube,
    HP_Wall,
    HP_Pistol,
    HP_Trinket,
    HP_Tool,
    HP_Device,
    HP_Binoculars,
    HP_AR_Grip,
    HP_AR_Magazine,
    HP_AR_Barrel,
    HP_Flashlight,
    HP_HandleFlatSmall,
    HP_HandleFlatMedium,
    HP_HandleFlatLarge,
    HP_Disc,
    HP_Corner,
    HP_Push,
    HP_Match,
    HP_Cigarette,
    HP_Cigarette_Box,
    HP_HeadGrip,
    HP_Axe,
    HP_BaseballBat,
    HP_KnifeSlash,
    HP_KnifeStab,
    HP_BottleNeck,
    HP_BBQLighter,
    HP_Revolver45,
    HP_CrocodileClip,
    HP_LA_Rifle_Grip,
    HP_LA_Rifle_Barrel,
    HP_DB_Shotgun_Grip,
    HP_DB_Shotgun_Barrel,
    HP_HandleCylinderSmall,
    HP_HandleCylinderMedium,
    HP_HandleCylinderLarge,
    HP_Surface_Clench,
    HP_Open,
    HP_HandleKnobMedium,
    HP_HandleKnobLarge,
    HP_DialSmall,
    HP_BowGrip,
    HP_BowString,
    HP_Arrow,
    HP_Emote,
    HP_JournalOpen,
    HP_JournalClosed,
    HP_KarateChop,
    HP_FingerPoke,
    HP_ClosedFist,
    HP_LA_Rifle_Grip_Cocking,
    HP_BenelliSuperNova_Grip,
    HP_WoodPlank,
    HP_MAX UMETA(Hidden),
};
