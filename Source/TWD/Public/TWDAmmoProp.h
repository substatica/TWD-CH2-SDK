#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TWDWeaponActor.h"
#include "TWDAmmoProp.generated.h"

class UArrowComponent;
class UStaticMeshComponent;
class USDIPointGripComponent;
class ASDIInventoryActor;
class UObject;

UCLASS()
class TWD_API ATWDAmmoProp : public ATWDWeaponActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UStaticMeshComponent* AmmoMesh;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* GripLeft;
    
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    USDIPointGripComponent* GripRight;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIInventoryActor> LastReturnedCurrencyInstance;
    
public:
    UPROPERTY(BlueprintReadWrite, Instanced, VisibleAnywhere)
    UArrowComponent* InsertDirection;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    TSubclassOf<ASDIInventoryActor> AmmoCurrencyClass;
    
    ATWDAmmoProp(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    ASDIInventoryActor* GetCurrencyInstance(UObject* InventoryHolder, TSubclassOf<ASDIInventoryActor> CurrencyClass);
    
    UFUNCTION(BlueprintNativeEvent)
    void DropAmmoProp();
    
};

