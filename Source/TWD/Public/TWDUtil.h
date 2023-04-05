#pragma once
#include "CoreMinimal.h"
#include "SDIVRPlayerUtil.h"
#include "Kismet/GameplayStaticsTypes.h"
#include "EFactionReaction.h"
#include "EFaction.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "DialogueLine.h"
#include "Engine/EngineTypes.h"
#include "Chaos/ChaosEngineInterface.h"
#include "UObject/NoExportTypes.h"
#include "EDemoModeType.h"
#include "ETWDCharacterHitRegion.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "TWDUtil.generated.h"

class ATWDCharacter;
class USkeletalMeshComponent;
class UObject;
class UAkAudioEvent;
class AActor;
class UBTNode;
class UDataTable;
class UCurveFloat;
class UPrimitiveComponent;
class UTWDMapManager;
class UTWDGameProgression;
class UTWDGameInstance;
class UTWDGameEntitlements;
class UTWDGameAchievements;
class ATWDPlayerCharacter;
class UTWDPlayerBuffManager;
class ASDIHeldActor;
class UBlendSpaceBase;
class UAkComponent;

UCLASS()
class UTWDUtil : public USDIVRPlayerUtil {
    GENERATED_BODY()
public:
    UTWDUtil();
    UFUNCTION(BlueprintCallable)
    static void UpdateSkeletalMeshCollision(USkeletalMeshComponent* Mesh, const TArray<FName>& CutBones, const TArray<FName>& Disabled, const TArray<FName>& RestoredBones, const TArray<FName>& EnabledBones, TArray<int32>& EnabledBonesOut, bool bRemoveStrictlyBelow, bool bDisableStrictlyBelow);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SwitchOnFactionReactionToPlayer(const UObject* WorldContextObject, EFaction Faction, EFactionReaction& Reactions);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool SuggestProjectileVelocity(const UObject* WorldContextObject, FVector& OutTossVelocity, FVector StartLocation, FVector EndLocation, float LaunchSpeed, float OverrideGravityZ, TEnumAsByte<ESuggestProjVelocityTraceOption::Type> TraceOption, float CollisionRadius, bool bFavorHighArc, TArray<AActor*> ActorsToIgnore, bool bDrawDebug);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetSignificanceZBias(const UObject* WorldContextObject, float ZBias);
    
    UFUNCTION(BlueprintPure)
    static bool PublicCheatsAllowed();
    
    UFUNCTION(BlueprintCallable)
    static bool PostAkEvent(UAkAudioEvent* AudioEvent, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool PlaySoundObjectAttached(AActor* AttachActor, UObject* SoundObj);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool PlaySoundObjectAtLocation(UObject* WorldContextObject, UObject* SoundObj, const FVector& Location);
    
    UFUNCTION(BlueprintPure)
    static FRotator OrientToNormal(const FVector& Normal, TEnumAsByte<EAxis::Type> OrientAxis, FRotator InRotation);
    
    UFUNCTION(BlueprintPure)
    static FBlackboardKeySelector MakeBlackboardKeySelector(UBTNode* NodeOwner, FName KeyName);
    
    UFUNCTION(BlueprintCallable)
    static void LoadDialogueLine(const FString& CacheName, UPARAM(Ref) FDialogueLine& DialogueLine);
    
    UFUNCTION(BlueprintCallable)
    static void LoadDataTablesAsDialogueLines(const TArray<UDataTable*>& DataTables);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FVector K2ComputeProjectileAimAssistanceTargetHead(UObject* WorldContextObject, const FVector& StartLocation, const FVector& InitialVelocity, const TArray<AActor*>& ActorsToIgnore, TEnumAsByte<ECollisionChannel> CollisionChannel, float PathCollisionRadius, float PathCollisionTime, float TargetRadius, const UCurveFloat* TargetRadiusCurve, float TargetZOffset, const UCurveFloat* TargetZOffsetCurve, float MinResultSpeed, bool bAdjustForTargetVelocity, float DebugRenderTime);
    
    UFUNCTION(BlueprintPure)
    static bool IsFriendlyInLOF(ATWDCharacter* Shooter, ATWDCharacter* Target);
    
    UFUNCTION(BlueprintPure)
    static bool IsCombatEnemy(const ATWDCharacter* RelationSubject, const ATWDCharacter* RelationObject);
    
    UFUNCTION(BlueprintPure)
    static bool IsCombatAlly(const ATWDCharacter* RelationSubject, const ATWDCharacter* RelationObject);
    
    UFUNCTION(BlueprintCallable)
    static bool IsChapterTwoEnabled();
    
    UFUNCTION(BlueprintPure)
    static bool HasLOS(ATWDCharacter* Character, UPrimitiveComponent* ComponentToTest);
    
    UFUNCTION(BlueprintPure)
    static bool HasActiveAkEvents(AActor* Actor);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UTWDMapManager* GetTWDMapManager(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UTWDGameProgression* GetTWDGameProgression(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UTWDGameInstance* GetTWDGameInstance(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UTWDGameEntitlements* GetTWDGameEntitlements(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UTWDGameAchievements* GetTWDGameAchievements(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static FBox GetTargetBounds(const USkeletalMeshComponent* Target, FName TargetSocketName);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static float GetSignificanceZBias(const UObject* WorldContextObject);
    
    UFUNCTION()
    static TArray<UDataTable*> GetReferencedDataTables(const FName PackageName);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ATWDPlayerCharacter* GetLocalPlayerCharacter(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static UTWDPlayerBuffManager* GetHoldingPlayerBuffManager(const ASDIHeldActor* HeldActor);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static EDemoModeType GetDemoMode(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static void GetCombatRelation(const ATWDCharacter* RelationSubject, const ATWDCharacter* RelationObject, bool& bIsAlly, bool& bIsEnemy);
    
    UFUNCTION(BlueprintPure)
    static ETWDCharacterHitRegion GetCharacterHitRegion(USkeletalMeshComponent* Mesh, FName BoneName);
    
    UFUNCTION(BlueprintPure)
    static void GetBuildConfiguration(FString& outConfiguration);
    
    UFUNCTION(BlueprintPure)
    static float GetAnimationLength(UBlendSpaceBase* BlendSpace, FVector BlendInput);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static void GetActiveStream(const UObject* WorldContextObject, bool& bValidStream, FRandomStream& ActiveStream);
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FText FormatTextForGender(const UObject* WorldContextObject, FText InText);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void EnableAutoSaving(const UObject* WorldContextObject, bool bForce);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DisableAutoSavingForDuration(const UObject* WorldContextObject, float Duration);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void DisableAutoSaving(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static bool DebugMenuAllowed();
    
    UFUNCTION(BlueprintCallable)
    static void CreateNoise(AActor* Instigator, const FVector& Location, float Radius, float VolumeMultiplier, UAkAudioEvent* AudioEvent, UAkComponent* InAkComponent, FName Tag);
    
    UFUNCTION(BlueprintPure)
    static FVector ClampPointToCapsule(const FVector& Point, const FTransform& CapsuleTransform, float CapsuleHalfHeight, float CapsuleRadius, float FudgeFactor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void CheckPoint(const UObject* WorldContextObject, bool bBeforeThisMoment);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ApplySphericalRadiusImpulses(UObject* WorldContextObject, const FVector& Location, float ImpulseRadius, float ImpulseStrength, const TArray<AActor*>& ActorsToIgnore, TEnumAsByte<ERadialImpulseFalloff> FalloffMode);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AddSuspendedLevelSaveContext(const UObject* WorldContextObject, const FString& SaveContext);
    
    UFUNCTION(BlueprintPure)
    static FBox Add(FBox A, FBox B);
    
};

