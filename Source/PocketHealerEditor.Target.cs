// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class PocketHealerEditorTarget : TargetRules
{
	public PocketHealerEditorTarget(TargetInfo Target) : base(Target)
	{
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "PocketHealer" } );
	}
}
