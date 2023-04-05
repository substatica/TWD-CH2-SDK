#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EMapTerritoryNodeType.h"
#include "TWDAchievementData.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct TWD_API FTWDAchievementData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfKilledHumans;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfGrapplesStarted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfTimesBrainedWalker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfTimesBrainedWalkerWithScrewDriver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfTimesBrainedWalkerWithSpikedBat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfTimesBrainedEliteWalkerWithAxe;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfKillsWithPropaneTankExplosion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfKillsOfUnawareEnemy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfTwinkiesEaten;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfLowQualityFoodEaten;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfTimesUsedGutsMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfTimesGivenItemToBeggar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    float DistanceClimbed;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    TSet<TSubclassOf<AActor>> CraftedItemTypes;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSet<TSubclassOf<AActor>> CraftedMedicalItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfGearTableItemsCrafted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfSurvivalTableItemsCrafted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfGunTableItemsCrafted;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSet<TSubclassOf<AActor>> CraftedFoodItemTypes;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    TSet<TSubclassOf<AActor>> ConsumedFoodItemTypes;
    
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    TSet<TSubclassOf<AActor>> ConsumedFoodItemTypesToday;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfFoodItemsConsumedToday;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfAngelsInBus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfPillowsInBus;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSet<FName> VisitedMapNames;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSet<FString> UnlockedRecipes;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfHumansKilledWithEsteemedMortal;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfHumansKilledWithGrenadeLauncher;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfDissidentsKilled;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfLivingEradicatorsKilled;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfUndeadEradicatorsKilled;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSet<EMapTerritoryNodeType> TerritoriesToCompleteExileOrders;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSet<EMapTerritoryNodeType> ExileLeadersKilledTerritories;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfEnemiesKilledWithGrenadeLauncher;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfTowerSoldiersKilled;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfLaserSightHeadshots;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfHumansKilledWithElephantGun;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfEnemiesKilledWithChainsaw;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfNightItemsScavenged;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfWalkersKilledWithSMG;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfWalkersKilledWithSapGloves;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfHumansKilledWithSapGloves;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfWalkersKilledWithSawedOff;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfEnemiesKilledWithSilencedWeaponsUndetected;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfDemonsInBus;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfBackpackItemsScavenged;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    int32 NumberOfRetributionsAchievements;
    
    FTWDAchievementData();
};

