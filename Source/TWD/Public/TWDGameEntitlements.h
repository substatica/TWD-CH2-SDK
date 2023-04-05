#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TWDGameEntitlements.generated.h"

class UDataTable;

UCLASS(BlueprintType)
class TWD_API UTWDGameEntitlements : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    bool bEntitlementSystemReady;
    
    UPROPERTY(Transient)
    UDataTable* PurchaseEntitlementTable;
    
    UPROPERTY(Transient)
    UDataTable* ProductEntitlementMapTable;
    
    UPROPERTY(Transient)
    TArray<FName> ProductEntitlementCache;
    
    UPROPERTY(Transient)
    UDataTable* FakeSkuTable;
    
public:
    UTWDGameEntitlements();
    UFUNCTION(BlueprintPure)
    bool IsEntitlementSystemReady() const;
    
    UFUNCTION(BlueprintCallable)
    bool CheckEntitlement(const FName& TwdEntitlementName);
    
};

