#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SDIConsoleCommandsManager.generated.h"

class USDIConsoleCommands;

UCLASS(ClassGroup=Custom, Within=PlayerController, meta=(BlueprintSpawnableComponent))
class USDIConsoleCommandsManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<USDIConsoleCommands>> ConsoleCommandsClasses;
    
private:
    UPROPERTY(Transient)
    TArray<USDIConsoleCommands*> ConsoleCommands;
    
public:
    USDIConsoleCommandsManager();
};

