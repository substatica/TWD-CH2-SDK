using UnrealBuildTool;

public class SDIVRPlayerPlugin : ModuleRules {
    public SDIVRPlayerPlugin(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "AkAudio",
            "AnimGraphRuntime",
            "AnimationCore",
            "AudioMixer",
            "Chaos",
            "CinematicCamera",
            "Core",
            "CoreUObject",
            "DeveloperSettings",
            "Engine",
            "GameplayCameras",
            "GameplayTags",
            "GameplayTasks",
            "HeadMountedDisplay",
            "InputCore",
            "MovieScene",
            "MovieSceneTracks",
            "NavigationSystem",
            "PhysicsCore",
            "PropertyPath",
            "SDICorePlugin",
            "SDISkinPlugin",
            "SDIStimAndResponsePlugin",
            "SDITuningPlugin",
            "SignificanceManager",
            "Slate",
            "SlateCore",
            "TemplateSequence",
            "UMG",
        });
    }
}
