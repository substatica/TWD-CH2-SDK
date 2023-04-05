#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SDICoreUtilityAIStateWander.h"
#include "RFloatExp.h"
#include "GameplayTagContainer.h"
#include "SDICoreUtilityAIStateFollowPath.generated.h"

class USDICoreUtilityAIStateFollowPath;
class ASDIPath;

UCLASS()
class SDICOREPLUGIN_API USDICoreUtilityAIStateFollowPath : public USDICoreUtilityAIStateWander {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    FRFloatExp PathPointRadius;
    
    UPROPERTY(EditAnywhere)
    FGameplayTag PreferredTag;
    
    UPROPERTY(Transient)
    int32 StartPathId;
    
    UPROPERTY(Transient)
    bool bStartPath;
    
    UPROPERTY(Transient)
    bool bIsPathCompleted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bLooping;
    
    UPROPERTY(Transient)
    bool bIsScreenShotNode;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    ASDIPath* ChosenPath;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 LastPathId;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 CurrentPathId;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    FVector CurrentPathLoc;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    int32 CurrentPathLocRetries;
    
public:
    USDICoreUtilityAIStateFollowPath();
protected:
    UFUNCTION(BlueprintNativeEvent)
    bool UpdatePathLocation(float DeltaSeconds);
    
    UFUNCTION(BlueprintNativeEvent)
    bool TransferPathTo(USDICoreUtilityAIStateFollowPath* NewState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetNextPathId(ASDIPath* Path, int32 ID, int32 PreviousId);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ASDIPath* FindNewPath(int32& OutClosestId);
    
protected:
    UFUNCTION(BlueprintNativeEvent)
    void ClearPath();
    
};

