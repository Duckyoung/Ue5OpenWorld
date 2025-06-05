// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DynamicOpenWorld : ModuleRules
{
	public DynamicOpenWorld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
