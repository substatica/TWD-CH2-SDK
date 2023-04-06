#pragma once
#include "CoreMinimal.h"
#include "ETWDInventoryType.h"
#include "UObject/NoExportTypes.h"
#include "ETWDLootType.h"
#include "ETWDNonVREquipmentType.h"
#include "UObject/NoExportTypes.h"
#include "TWDInventoryActorInterfaceData.generated.h"

class UAkAudioEvent;
class UTWDRecipe;
class UMaterialInterface;

USTRUCT(BlueprintType)
struct FTWDInventoryActorInterfaceData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ETWDInventoryType InventoryType;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ETWDLootType LootType;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ETWDNonVREquipmentType NonVREquipmentType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName OnlineEntitlementName;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float SharpnessRating;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DurabilityRating;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float ThrowRating;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString SerializationString;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    FGuid PlacedObjectId;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNearbyHighlightShown;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bIgnorePositioningForInventoryData;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bNeverShowInventoryData;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDropOnArmGrapple;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bDropOnArmGrappleOnlyIfTwoHanded;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    bool bApplyPrimaryGripPitchOffsetUserSetting;
    
    UPROPERTY(BlueprintReadWrite)
    FTransform BackpackSlotTransform;
    
    UPROPERTY(BlueprintReadWrite)
    FTransform CharacterSlotTransform;
    
    UPROPERTY(BlueprintReadWrite)
    FTransform ShoulderSlotTransform;
    
    UPROPERTY(BlueprintReadWrite)
    FTransform NonVRInteractTransform;
    
    UPROPERTY(VisibleDefaultsOnly)
    bool bNonVRInteractTransformIsValid;
    
    UPROPERTY()
    bool bSheathed;
    
    UPROPERTY(Transient)
    uint8 LocalInventorySlotIdx;
    
    UPROPERTY(Transient)
    bool bIgnoreReturnToInventoryAudio;
    
    UPROPERTY()
    TArray<UMaterialInterface*> OriginalMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* AudioStoreInInventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UAkAudioEvent* AudioRemoveFromInventory;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSoftClassPtr<UTWDRecipe> SalvageRecipe;
    
    UPROPERTY(BlueprintReadWrite)
    FGuid SalvageRecipeGuid;
    
    TWD_API FTWDInventoryActorInterfaceData();
};

