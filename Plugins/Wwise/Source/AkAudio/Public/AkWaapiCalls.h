#pragma once
#include "CoreMinimal.h"
#include "OnWaapiProjectLoadedDelegate.h"
#include "AKWaapiJsonObject.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OnEventCallbackDelegate.h"
#include "AkWaapiSubscriptionId.h"
#include "OnWaapiConnectionLostDelegate.h"
#include "AkWaapiUri.h"
#include "AkWaapiCalls.generated.h"

UCLASS(BlueprintType, DefaultConfig, Within=World)
class AKAUDIO_API UAkWaapiCalls : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAkWaapiCalls();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static FAKWaapiJsonObject Unsubscribe(const FAkWaapiSubscriptionId& SubscriptionId, bool& UnsubscriptionDone);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static FAKWaapiJsonObject SubscribeToWaapi(const FAkWaapiUri& WaapiUri, const FAKWaapiJsonObject& WaapiOptions, const FOnEventCallback& Callback, FAkWaapiSubscriptionId& SubscriptionId, bool& SubscriptionDone);
    
    UFUNCTION(BlueprintCallable)
    static void SetSubscriptionID(const FAkWaapiSubscriptionId& Subscription, int32 ID);
    
    UFUNCTION(BlueprintCallable)
    static bool RegisterWaapiProjectLoadedCallback(const FOnWaapiProjectLoaded& Callback);
    
    UFUNCTION(BlueprintCallable)
    static bool RegisterWaapiConnectionLostCallback(const FOnWaapiConnectionLost& Callback);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetSubscriptionID(const FAkWaapiSubscriptionId& Subscription);
    
    UFUNCTION(BlueprintPure)
    static FText Conv_FAkWaapiSubscriptionIdToText(const FAkWaapiSubscriptionId& INAkWaapiSubscriptionId);
    
    UFUNCTION(BlueprintPure)
    static FString Conv_FAkWaapiSubscriptionIdToString(const FAkWaapiSubscriptionId& INAkWaapiSubscriptionId);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    static FAKWaapiJsonObject CallWaapi(const FAkWaapiUri& WaapiUri, const FAKWaapiJsonObject& WaapiArgs, const FAKWaapiJsonObject& WaapiOptions);
    
};

