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
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UStaticMeshComponent* AmmoMesh;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* GripLeft;
    
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    USDIPointGripComponent* GripRight;
    
    UPROPERTY(Transient)
    TWeakObjectPtr<ASDIInventoryActor> LastReturnedCurrencyInstance;
    
public:
    UPROPERTY(BlueprintReadOnly, Instanced, VisibleAnywhere)
    UArrowComponent* InsertDirection;
    
    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
    TSubclassOf<ASDIInventoryActor> AmmoCurrencyClass;
    
    ATWDAmmoProp();
    UFUNCTION(BlueprintCallable)
    ASDIInventoryActor* GetCurrencyInstance(UObject* InventoryHolder, TSubclassOf<ASDIInventoryActor> CurrencyClass);
    
    UFUNCTION(BlueprintNativeEvent)
    void DropAmmoProp();
    
};

