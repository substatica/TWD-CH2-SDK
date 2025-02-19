/********************************************************************************
The content of the files in this repository include portions of the AUDIOKINETIC
Wwise Technology released in source code form as part of the SDK package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
********************************************************************************/

#pragma once

#include "AkAssetBase.h"
#include "AkAuxBus.generated.h"

class UAkAudioBank;

UCLASS(hidecategories=(Advanced, Attachment, Volume), BlueprintType)
class AKAUDIO_API UAkAuxBus : public UAkAssetBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "AkAuxBus")
		UAkAudioBank* RequiredBank = nullptr;

#if WITH_EDITOR
	UAkAssetData* FindOrAddAssetData(const FString& Platform, const FString& Language) override;
#endif

protected:
	UAkAssetData* CreateAssetData(UObject* Parent) const override;
};
