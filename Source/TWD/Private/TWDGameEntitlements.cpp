#include "TWDGameEntitlements.h"

bool UTWDGameEntitlements::IsEntitlementSystemReady() const {
    return false;
}

bool UTWDGameEntitlements::CheckEntitlement(const FName& TwdEntitlementName) {
    return false;
}

UTWDGameEntitlements::UTWDGameEntitlements() {
    this->bEntitlementSystemReady = false;
    this->PurchaseEntitlementTable = NULL;
    this->ProductEntitlementMapTable = NULL;
    this->FakeSkuTable = NULL;
}

