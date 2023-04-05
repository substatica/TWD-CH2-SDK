using UnrealBuildTool;

public class TWD : ModuleRules {
    public TWD(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bLegacyPublicIncludePaths = false;
        ShadowVariableWarningLevel = WarningLevel.Warning;
        
        PublicDependencyModuleNames.AddRange(new string[] {
            "AIModule",
            "AkAudio",
            "AnimGraphRuntime",
            "AnimationCore",
            "Annosoft",
            "ApexDestruction",
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
            "Gauntlet",
            "HeadMountedDisplay",
            "InputCore",
            "MovieScene",
            "MovieSceneTracks",
            "NavigationSystem",
            "PhysicsCore",
            "PropertyPath",
            "SDICorePlugin",
            "SDISaveImportExportPlugin",
            "SDISkinPlugin",
            "SDIStimAndResponsePlugin",
            "SDITuningPlugin",
            "SDIVRPlayerPlugin",
            "SignificanceManager",
            "Slate",
            "SlateCore",
            "TemplateSequence",
            "UMG",
        });
    }
}
