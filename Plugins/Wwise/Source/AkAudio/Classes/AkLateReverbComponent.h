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
#include "Components/SceneComponent.h"
#include "AkLateReverbComponent.generated.h"


UCLASS(ClassGroup = Audiokinetic, BlueprintType, hidecategories = (Transform, Rendering, Mobility, LOD, Component, Activation, Tags), meta = (BlueprintSpawnableComponent))
class AKAUDIO_API UAkLateReverbComponent : public USceneComponent
{
	GENERATED_UCLASS_BODY()

	/**
	 * Enable usage of the late reverb inside a volume. Additional properties are available in the Late Reverb category.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Toggle, meta = (DisplayName = "Enable Late Reverb"))
	uint32 bEnable:1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LateReverb")
	class UAkAuxBus * AuxBus;

	/** Wwise Auxiliary Bus associated to this AkReverbVolume */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "LateReverb")
	FString AuxBusName;

	/** Maximum send level to the Wwise Auxiliary Bus associated to this AkReverbVolume */
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "LateReverb", meta = (ClampMin = 0.0f, ClampMax = 1.0f, UIMin = 0.0f, UIMax = 1.0f))
	float SendLevel;

	/** Rate at which to fade in/out the SendLevel of the current Reverb Volume when entering/exiting it, in percentage per second (0.2 will make the fade time 5 seconds) */
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "LateReverb" ,meta = (ClampMin = 0.0f, UIMin = 0.0f))
	float FadeRate;

	/**
	 * The precedence in which the AkReverbVolumes will be applied. In the case of overlapping volumes, only the ones 
	 * with the highest priority are chosen (the number of simultaneous AkReverbVolumes is configurable in the Unreal 
	 * Editor Project Settings under Plugins > Wwise). If two or more overlapping AkReverbVolumes have the same 
	 * priority, the chosen AkReverbVolume is unpredictable. 
	 * If this Late Reverb is applied to a Spatial Audio room, it will be active even if the maximum number of simultaneous reverb volumes (see integration settings) was reached. 
	 * Sound emitted by game objects in a room will always be sent to the room late reverb independently of other late reverbs in the scene.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LateReverb")
	float Priority;

	/** Get the AkAuxBusId associated to AuxBusName */
	uint32 GetAuxBusId() const;

	/** We keep a  linked list of ReverbVolumes sorted by priority for faster finding of reverb volumes at a specific location.
	 *	This points to the next volume in the list.
	 */
	UPROPERTY(transient)
	class UAkLateReverbComponent* NextLowerPriorityComponent;

	bool HasEffectOnLocation(const FVector& Location) const;

	bool LateReverbIsActive() const { return ParentVolume && bEnable && !IsRunningCommandlet(); }

	virtual void PostLoad() override;
	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
private:
	class AVolume* ParentVolume;
	void InitializeParentVolume();
};
