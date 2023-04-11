#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AIController.h"
#include "ESDIUtilityAIDifficulty.h"
#include "SDICoreUtilityAIController.generated.h"

class ACharacter;
class USDICoreUtilityAI;
class UBehaviorTree;
class UBlackboardComponent;

UCLASS()
class SDICOREPLUGIN_API ASDICoreUtilityAIController : public AAIController {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    TSubclassOf<USDICoreUtilityAI> UtilityAIClass;
    
    UPROPERTY(EditDefaultsOnly)
    bool bUtilityAIEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    ESDIUtilityAIDifficulty Difficulty;
    
    UPROPERTY(Transient)
    TSubclassOf<USDICoreUtilityAI> LastCharacterUtilityAIClass;
    
    UPROPERTY(BlueprintReadWrite, Transient)
    USDICoreUtilityAI* UtilityAI;
    
public:
    ASDICoreUtilityAIController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    bool UtilityAIEnabled() const;
    
protected:
    UFUNCTION()
    void UpdateUtilityAI();
    
public:
    UFUNCTION(BlueprintCallable)
    bool StopBehaviorTree(UBehaviorTree* BTAsset);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetUtilityAIEnabled(bool bEnabled);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetDifficulty(ESDIUtilityAIDifficulty NewDifficulty);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetAIName(const FString& AIName);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    bool IsUsingUtilityAI() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    USDICoreUtilityAI* GetUtilityAI() const;
    
    UFUNCTION(BlueprintPure)
    float GetServerTimestamp() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    ESDIUtilityAIDifficulty GetDifficulty() const;
    
    UFUNCTION(BlueprintPure)
    ACharacter* GetChar() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    UBlackboardComponent* GetBlackboard() const;
    
};

