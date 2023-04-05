﻿using UnrealBuildTool;

public class TWDEditorTarget : TargetRules {
	public TWDEditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new string[] {
			"TWD",
		});
	}
}
