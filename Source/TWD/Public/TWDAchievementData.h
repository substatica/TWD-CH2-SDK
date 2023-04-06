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
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TSet<TSubclassOf<AActor>> CraftedItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSet<TSubclassOf<AActor>> CraftedMedicalItemTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfGearTableItemsCrafted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfSurvivalTableItemsCrafted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfGunTableItemsCrafted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSet<TSubclassOf<AActor>> CraftedFoodItemTypes;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TSet<TSubclassOf<AActor>> ConsumedFoodItemTypes;
    
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
    TSet<TSubclassOf<AActor>> ConsumedFoodItemTypesToday;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfFoodItemsConsumedToday;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfAngelsInBus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfPillowsInBus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSet<FName> VisitedMapNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSet<FString> UnlockedRecipes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfHumansKilledWithEsteemedMortal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfHumansKilledWithGrenadeLauncher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfDissidentsKilled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfLivingEradicatorsKilled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfUndeadEradicatorsKilled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSet<EMapTerritoryNodeType> TerritoriesToCompleteExileOrders;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSet<EMapTerritoryNodeType> ExileLeadersKilledTerritories;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfEnemiesKilledWithGrenadeLauncher;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfTowerSoldiersKilled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfLaserSightHeadshots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfHumansKilledWithElephantGun;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfEnemiesKilledWithChainsaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfNightItemsScavenged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfWalkersKilledWithSMG;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfWalkersKilledWithSapGloves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfHumansKilledWithSapGloves;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfWalkersKilledWithSawedOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfEnemiesKilledWithSilencedWeaponsUndetected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfDemonsInBus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfBackpackItemsScavenged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 NumberOfRetributionsAchievements;
    
    FTWDAchievementData();
};

